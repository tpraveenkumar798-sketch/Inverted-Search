#include "inverted.h"

void save_database(hash *HT)
{
    FILE *fp;
    char backup_file[100];

    printf("Enter the backup file name: ");
    scanf("%99s", backup_file);

    /* Validate an existing file before overwriting it. */
    fp = fopen(backup_file, "r");

    if (fp != NULL)
    {
        int first = fgetc(fp);
        int last = EOF;
        long pos;

        fseek(fp, 0, SEEK_END);
        pos = ftell(fp);

        while (pos > 0)
        {
            fseek(fp, --pos, SEEK_SET);
            last = fgetc(fp);

            if (last != '\n' && last != '\r')
                break;
        }

        fclose(fp);

        if (first == '#' && last == '#')
            printf("Valid backup file. It will be overwritten.\n");
        else
            printf("Existing file is not a valid backup file. It will be overwritten.\n");
    }

    fp = fopen(backup_file, "w");
    if (fp == NULL)
    {
        printf("Unable to open backup file\n");
        return;
    }

    for (int i = 0; i < 27; i++)
    {
        M_node *mtemp = HT[i].M_link;

        while (mtemp != NULL)
        {
            fprintf(fp, "#%d;%s;%d;", i, mtemp->word, mtemp->file_count);

            S_node *stemp = mtemp->sub_link;
            while (stemp != NULL)
            {
                fprintf(fp, "%s;%d;", stemp->filename, stemp->word_count);
                stemp = stemp->sub_link;
            }

            fprintf(fp, "#\n");
            mtemp = mtemp->main_link;
        }
    }

    fclose(fp);
    printf("Database saved successfully in %s\n", backup_file);
}
