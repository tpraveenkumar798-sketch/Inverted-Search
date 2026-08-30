#include "inverted.h"

int insert_last(F_node **head, char *f_name)
{
    F_node *new = malloc(sizeof(F_node));

    if (new == NULL)
    {
        printf("Memory allocation failed\n");
        return failure;
    }

    strncpy(new->f_name, f_name, sizeof(new->f_name) - 1);
    new->f_name[sizeof(new->f_name) - 1] = '\0';
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
        return success;
    }

    F_node *temp = *head;
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = new;
    return success;
}
