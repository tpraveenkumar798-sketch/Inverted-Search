📌 Project Overview

**Inverted Search** is a C programming project that creates an efficient word-based index from multiple text files.

Instead of searching every file individually, the program creates an **inverted index** that maps each word to the files in which it appears and stores the number of occurrences.

🎯 Objectives

Create an inverted index for multiple .txt files.
Store words using a hash table.
Maintain file-wise word counts.
Search for words efficiently.
Save the database into a backup file.
Restore and update the database using a backup file.
Add new text files to an existing database.
Practice dynamic memory allocation and linked-list manipulation.

🧠 Data Structures Used

The project mainly uses a Hash Table + Linked Lists.

Hash Table

The hash table contains 27 indexes:

0 - 25 → Alphabet-based indexes
26     → Special characters / numbers

Each index points to a linked list of main nodes.

Hash Table

   +-- [0] --> Main Node --> Main Node
   
   +-- [1] --> Main Node
   
   +-- [2] --> Main Node --> Main Node
   ...
   ...
   ...
   +-- [26] --> Main Node
   
Main Node

Each main node stores:

Word
File Count
Sub Node Link
Main Node Link

Example:

       Word: file
       File Count: 2
             |
             v   
        +----------+
        | s1.txt   |
        | count: 2 |
        +----------+
             |
             v
        +----------+
        | new.txt  |
        | count: 1 |
        +----------+
Sub Node

The sub node stores:

File name
Number of occurrences
Link to the next file

🏗️ Project Structure

Inverted_search

├── inverted.h

├── inverted.c

├── main.c

├── create.c

├── display.c

├── search.c

├── save.c

├── update.c

├── insertl.c

├── Makefile

├── s.txt

├── s1.txt

├── new.txt

└── backup.txt

📂 File Description

File	Description
main.c	Main menu and program execution
inverted.h	Structures, macros and function declarations
inverted.c	File validation and hash index calculation
create.c	Creates the inverted database
display.c	Displays the database
search.c	Searches for words
save.c	Saves database to backup file
update.c	Loads backup and adds new files
insertl.c	Handles file linked-list insertion
Makefile	Automates compilation
backup.txt	Stores saved database
*.txt	Input text files

🔄 Program Workflow

             Input Text Files
                    |
                    v
            Validate Files
                    |
                    v
             Create Database
                    |
                    v
              Hash Table
                    |
        +-----------+-----------+
        |           |           |
        v           v           v
     Display      Search       Save
                                |
                                v
                           backup.txt
                                |
                                v
                            Update
                                |
                                v
                          New .txt File
🛠️ Technologies Used

C Programming
Data Structures
Hash Tables
Linked Lists
File Handling
Dynamic Memory Allocation
Pointers
String Manipulation
Makefile
Linux / WSL

💻 Compilation

Using Makefile

Open the terminal inside the project directory:

make

This generates:

inverted_search
Run the Program
./inverted_search s.txt s1.txt

You can provide multiple text files:

./inverted_search file1.txt file2.txt file3.txt

🧹 Clean Build Files

To remove object files and the executable:

make clean

Then rebuild:

make

📝 Example Usage

Step 1: Run
./inverted_search s.txt s1.txt

Step 2: Create Database
Enter your choice : 1

Database created successfully

Step 3: Display
Enter your choice : 2

The inverted database will be displayed.

Step 4: Save
Enter your choice : 3

Enter the backup file name: backup.txt

Database saved successfully in backup.txt

Step 5: Update
Enter your choice : 5

Enter backup file name: backup.txt
Enter new file name: new.txt

Database updated successfully

The new file's words are added to the existing database.

🔐 Update Database Logic

The update operation follows this process:

              backup.txt
                  |
                  v
          Validate Backup
                  |
                  v
          Load Previous Data
                  |
                  v
             Hash Table
                  |
                  v
          Enter New .txt File
                  |
                  v
          Validate New File
                  |
                  v
       Check Duplicate File
             /          \
           Yes           No
            |             |
            v             v
          Reject      Add File
                          |
                          v
                  Create Database
                          |
                          v
                    Updated HT
📄 Backup File

The database can be stored in a structured format such as:

#0;An;1;s1.txt;1;#
#5;file;2;s1.txt;2;new.txt;1;#
#8;is;2;s.txt;1;s1.txt;4;#

The backup can later be used to reconstruct the database.

💡 Concepts Demonstrated

This project demonstrates practical implementation of:

Data Structures
Hash Table
Singly Linked List
Multi-level Linked List
C Programming
Structures
Pointers
Dynamic memory allocation
Functions
Arrays
Strings
File handling
File Operations
fopen()
fclose()
fscanf()
fprintf()
fgets()
fgetc()
Memory Management
malloc()
free()

🚀 Future Enhancements

Possible improvements include:

Case-insensitive searching
Removing punctuation from words
Sorting words alphabetically
Improved search performance
Support for larger text files
Better backup validation
Search suggestions
GUI-based interface
Support for more file formats

🎓 Learning Outcome

Through this project, I gained practical experience in:

Designing data structures
Implementing hash tables
Working with linked lists
Handling files in C
Managing dynamic memory
Using pointers and structures
Building modular C programs
Creating and using Makefiles
Working with Linux/WSL
Implementing database save and update functionality

👨‍💻 Author

T Praveen Kumar

C Programmer | Embedded Systems Enthusiast | Data Structures

⭐ Project Highlights

✔ Hash Table Implementation

✔ Linked List Implementation

✔ Multiple File Processing

✔ Word Frequency Counting

✔ Word Search

✔ Database Display

✔ Database Save

✔ Database Update

✔ Backup File Handling

✔ Dynamic Memory Management

✔ Makefile Build System
