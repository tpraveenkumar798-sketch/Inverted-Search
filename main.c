#include "inverted.h"

int main(int argc, char *argv[])
{

    F_node *head = NULL;
    hash HT[27];
    int flag=0;
    int sflag=0;

    for (int i = 0; i < 27; i++)
    {
        HT[i].index = i;
        HT[i].M_link = NULL;
    }

    if (validate_files(argc, argv, &head) != success)
        return failure;

    print_filenames(head);

    int option;

    do
    {
        printf("\nSelect your choice among following operations:\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Save Database\n");
        printf("4. Search\n");
        printf("5. Update Database\n");
        printf("6. Exit\n");
        printf("\nEnter your choice : ");

        if (scanf("%d", &option) != 1)
        {
            printf("INFO : Please enter a valid option\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (option)
        {
            case 1:
                if(flag==0)
                {
                    if (create_database(HT, head) == success)
                    {
                        flag=1;
                        printf("Database created successfully\n");
                    }
                }
                else
                {
                    printf("database already created for this files\n");
                    return 0;
                }
                    
                break;

            case 2:
                display_database(HT);
                break;

            case 3:
                save_database(HT);
                break;

            case 4:
                search_database(HT);
                break;

            case 5:

                    update_database(HT, &head);
                    
                break;

            case 6:
                break;

            default:
                printf("INFO : Please enter a valid option\n");
        }
    } while (option != 6);

    clear_database(HT);

    while (head != NULL)
    {
        F_node *temp = head->link;
        free(head);
        head = temp;
    }

    return success;
}
