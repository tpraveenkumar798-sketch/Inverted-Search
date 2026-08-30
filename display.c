#include "inverted.h"

void display_database(hash *HT)
{
    printf(BOLD BLUE
           "+-------+----------------+------------+----------------------+------------+\n"
           "| Index | Word           | File Count | File Name            | Word Count |\n"
           "+-------+----------------+------------+----------------------+------------+\n"
           RESET);

    for (int i = 0; i < 27; i++)
    {
        M_node *mtemp = HT[i].M_link;

        while (mtemp != NULL)
        {
            S_node *stemp = mtemp->sub_link;
            int first = 1;

            while (stemp != NULL)
            {
                if (first)
                {
                    printf("| " BOLD BLUE "%-5d" RESET
                           " | " BOLD BLUE "%-14s" RESET
                           " | " BOLD BLUE "%-10d" RESET
                           " | " BOLD BLUE "%-20s" RESET
                           " | " BOLD BLUE "%-10d" RESET " |\n",
                           i, mtemp->word, mtemp->file_count,
                           stemp->filename, stemp->word_count);
                    first = 0;
                }
                else
                {
                    printf("| %-5s | %-14s | %-10s | " CYAN "%-20s" RESET
                           " | " RED "%-10d" RESET " |\n",
                           "", "", "", stemp->filename, stemp->word_count);
                }

                stemp = stemp->sub_link;
            }

            mtemp = mtemp->main_link;
        }
    }

    printf(BOLD BLUE
           "+-------+----------------+------------+----------------------+------------+\n"
           RESET);
}
