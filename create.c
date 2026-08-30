#include "inverted.h"

int create_database(hash *HT, F_node *head)
{
    F_node *temp = head;

    while (temp != NULL)
    {
        FILE *fp = fopen(temp->f_name, "r");

        if (fp == NULL)
        {
            printf("Unable to open %s\n", temp->f_name);
            temp = temp->link;
            continue;
        }

        char str[25];

        while (fscanf(fp, "%24s", str) == 1)
        {
            int key = get_index(str);
            M_node *mtemp = HT[key].M_link;
            M_node *mprev = NULL;

            while (mtemp != NULL && strcmp(mtemp->word, str) != 0)
            {
                mprev = mtemp;
                mtemp = mtemp->main_link;
            }

            if (mtemp == NULL)
            {
                M_node *mnew = malloc(sizeof(M_node));
                S_node *snew = malloc(sizeof(S_node));

                if (mnew == NULL || snew == NULL)
                {
                    free(mnew);
                    free(snew);
                    fclose(fp);
                    return failure;
                }

                strcpy(mnew->word, str);
                mnew->file_count = 1;
                mnew->main_link = NULL;
                mnew->sub_link = snew;

                strcpy(snew->filename, temp->f_name);
                snew->word_count = 1;
                snew->sub_link = NULL;

                if (mprev == NULL)
                    HT[key].M_link = mnew;
                else
                    mprev->main_link = mnew;
            }
            else
            {
                S_node *stemp = mtemp->sub_link;
                S_node *sprev = NULL;

                while (stemp != NULL && strcmp(stemp->filename, temp->f_name) != 0)
                {
                    sprev = stemp;
                    stemp = stemp->sub_link;
                }

                if (stemp != NULL)
                {
                    stemp->word_count++;
                }
                else
                {
                    S_node *snew = malloc(sizeof(S_node));

                    if (snew == NULL)
                    {
                        fclose(fp);
                        return failure;
                    }

                    strcpy(snew->filename, temp->f_name);
                    snew->word_count = 1;
                    snew->sub_link = NULL;

                    sprev->sub_link = snew;
                    mtemp->file_count++;
                }
            }
        }

        fclose(fp);
        temp = temp->link;
    }

    return success;
}
