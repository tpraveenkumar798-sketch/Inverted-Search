#include "inverted.h"

int search_database(hash *HT)
{
    char str[25];

    printf("Enter the word you want to search: ");
    scanf("%24s", str);

    int key = get_index(str);
    M_node *mtemp = HT[key].M_link;

    while (mtemp != NULL)
    {
        if (strcmp(mtemp->word, str) == 0)
            break;

        mtemp = mtemp->main_link;
    }

    if (mtemp == NULL)
    {
        printf("Word Not Found\n");
        return failure;
    }

    printf("Word %s is present in %d files\n", str, mtemp->file_count);

    S_node *stemp = mtemp->sub_link;
    while (stemp != NULL)
    {
        printf("IN FILE: %s word %s is present %d times\n",
               stemp->filename, str, stemp->word_count);
        stemp = stemp->sub_link;
    }

    return success;
}
