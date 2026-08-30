#include "inverted.h"

int file_exists_in_backup(char *backup_file, char *filename)
{
    FILE *fp;
    char line[500];

    fp = fopen(backup_file, "r");

    if (fp == NULL)
        return failure;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *token;

        line[strcspn(line, "\r\n")] = '\0';

        token = strtok(line, ";");

        if (token == NULL)
            continue;

        token = strtok(NULL, ";");

        if (token == NULL)
            continue;

        token = strtok(NULL, ";");

        if (token == NULL)
            continue;

        while ((token = strtok(NULL, ";")) != NULL)
        {
            if (strcmp(token, "#") == 0)
                break;

            if (strcmp(token, filename) == 0)
            {
                fclose(fp);
                return success;
            }

            token = strtok(NULL, ";");

            if (token == NULL)
                break;
        }
    }

    fclose(fp);

    return failure;
}

int load_database(hash *HT, char *backup_file)
{
    FILE *fp;
    char line[500];

    fp = fopen(backup_file, "r");

    if (fp == NULL)
        return failure;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        char *token;
        int index;
        int file_count;

        M_node *mnew;
        M_node *mtail;
        S_node *stail = NULL;

        line[strcspn(line, "\r\n")] = '\0';

        if (line[0] == '\0')
            continue;

        token = strtok(line, ";");

        if (token == NULL || token[0] != '#')
            continue;

        index = atoi(token + 1);

        if (index < 0 || index >= 27)
            continue;

        token = strtok(NULL, ";");

        if (token == NULL)
            continue;

        mnew = malloc(sizeof(M_node));

        if (mnew == NULL)
        {
            fclose(fp);
            return failure;
        }

        strcpy(mnew->word, token);

        token = strtok(NULL, ";");

        if (token == NULL)
        {
            free(mnew);
            continue;
        }

        file_count = atoi(token);

        mnew->file_count = file_count;
        mnew->main_link = NULL;
        mnew->sub_link = NULL;

        if (HT[index].M_link == NULL)
        {
            HT[index].M_link = mnew;
        }
        else
        {
            mtail = HT[index].M_link;

            while (mtail->main_link != NULL)
                mtail = mtail->main_link;

            mtail->main_link = mnew;
        }

        while ((token = strtok(NULL, ";")) != NULL)
        {
            S_node *snew;
            int word_count;

            if (strcmp(token, "#") == 0)
                break;

            snew = malloc(sizeof(S_node));

            if (snew == NULL)
            {
                fclose(fp);
                return failure;
            }

            strcpy(snew->filename, token);

            token = strtok(NULL, ";");

            if (token == NULL)
            {
                free(snew);
                break;
            }

            word_count = atoi(token);

            snew->word_count = word_count;
            snew->sub_link = NULL;

            if (mnew->sub_link == NULL)
            {
                mnew->sub_link = snew;
            }
            else
            {
                stail->sub_link = snew;
            }

            stail = snew;
        }
    }

    fclose(fp);

    return success;
}

int update_database(hash *HT, F_node **head)
{
    char backup_file[100];
    char new_file[100];
    FILE *fp;

    printf("Enter the backup file name: ");
    scanf("%99s", backup_file);

    fp = fopen(backup_file, "r");

    if (fp == NULL)
    {
        printf("Backup file not found\n");
        return failure;
    }

    if (fgetc(fp) != '#')
    {
        printf("Invalid backup file\n");
        fclose(fp);
        return failure;
    }

    fclose(fp);

    clear_database(HT);

    if (load_database(HT, backup_file) == failure)
    {
        printf("Unable to load backup database\n");
        return failure;
    }

    printf("Backup database loaded successfully\n");

    printf("Enter the new file name: ");
    scanf("%99s", new_file);

    if (file_exists_in_backup(backup_file, new_file) == success)
    {
        printf("File already exists in backup\n");
        return failure;
    }

    fp = fopen(new_file, "r");

    if (fp == NULL)
    {
        printf("File %s is not found\n", new_file);
        return failure;
    }

    fclose(fp);

    F_node new_node;

    strcpy(new_node.f_name, new_file);
    new_node.link = NULL;

    if (create_database(HT, &new_node) == failure)
        return failure;

    printf("Database updated successfully\n");

    return success;
}
void clear_database(hash *HT)
{
    for (int i = 0; i < 27; i++)
    {
        M_node *mtemp = HT[i].M_link;

        while (mtemp != NULL)
        {
            M_node *mnext = mtemp->main_link;
            S_node *stemp = mtemp->sub_link;

            while (stemp != NULL)
            {
                S_node *snext = stemp->sub_link;
                free(stemp);
                stemp = snext;
            }

            free(mtemp);
            mtemp = mnext;
        }

        HT[i].M_link = NULL;
    }
}