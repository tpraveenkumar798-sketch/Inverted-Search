#include "inverted.h"

int get_index(char *word)
{
    unsigned char ch = (unsigned char)word[0];

    if (ch >= 'a' && ch <= 'z')
        return ch - 'a';

    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';

    return 26;
}

int check_duplicates(F_node *head, char *f_name)
{
    F_node *temp = head;

    while (temp != NULL)
    {
        if (strcmp(temp->f_name, f_name) == 0)
            return failure;

        temp = temp->link;
    }

    return success;
}

int validate_files(int argc, char *argv[], F_node **head)
{
    if (argc < 2)
    {
        printf("Enter the file names\n");
        return failure;
    }

    for (int i = 1; i < argc; i++)
    {
        size_t len = strlen(argv[i]);

        if (len == 0 || argv[i][0] == '.')
        {
            printf("Invalid file name: %s\n", argv[i]);
            return failure;
        }

        if (len < 4 || strcmp(argv[i] + len - 4, ".txt") != 0)
        {
            printf("Enter the files only with .txt extension\n");
            return failure;
        }

        if (check_duplicates(*head, argv[i]) == failure)
        {
            printf("Duplicate file entered: %s\n", argv[i]);
            return failure;
        }

        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL)
        {
            printf("File %s is not found\n", argv[i]);
            return failure;
        }

        if (fgetc(fp) == EOF)
        {
            printf("File %s is empty\n", argv[i]);
            fclose(fp);
            return failure;
        }

        fclose(fp);

        if (insert_last(head, argv[i]) == failure)
            return failure;
    }

    return success;
}

int print_filenames(F_node *head)
{
    printf("\n----------------------------------\n");
    printf("       Validated Files\n");
    printf("----------------------------------\n");

    while (head != NULL)
    {
        printf("-> %s\n", head->f_name);
        head = head->link;
    }

    printf("----------------------------------\n");
    return success;
}
