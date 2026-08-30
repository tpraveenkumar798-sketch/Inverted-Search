#ifndef INVERTED_H
#define INVERTED_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define success 1
#define failure 0

#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define RED     "\033[31m"
#define BOLD    "\033[1m"

typedef struct file
{
    char f_name[20];
    struct file *link;
} F_node;

typedef struct Sub
{
    int word_count;
    char filename[20];
    struct Sub *sub_link;
} S_node;

typedef struct Main
{
    char word[25];
    int file_count;
    S_node *sub_link;
    struct Main *main_link;
} M_node;

typedef struct Hashtable
{
    int index;
    M_node *M_link;
} hash;

int create_database(hash *HT, F_node *head);
void display_database(hash *HT);
int search_database(hash *HT);
void save_database(hash *HT);
int update_database(hash *HT, F_node **head);

int validate_files(int argc, char *argv[], F_node **head);
int insert_last(F_node **head, char *f_name);
int check_duplicates(F_node *head, char *f_name);
int print_filenames(F_node *head);
int get_index(char *word);

int file_exists_in_backup(char *backup_file, char *filename);
int load_database(hash *HT, char *backup_file);
void clear_database(hash *HT);

#endif
