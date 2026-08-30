# 🔎 Inverted Search

A C-based Inverted Search application that creates an efficient word index from multiple text files using a hash table and linked lists.

## 📌 Overview

The Inverted Search project is designed to index words present in multiple text files and provide information about where each word occurs.

The application creates an inverted database that stores:

- The word
- Number of files containing the word
- File names
- Number of occurrences of the word in each file

The project uses a 27-index hash table along with linked lists for efficient storage and searching.

## ✨ Features

- 🔹 Validate input text files
- 🔹 Check file existence and empty files
- 🔹 Detect duplicate file names
- 🔹 Create an inverted search database
- 🔹 Display the complete database
- 🔹 Search for a specific word
- 🔹 Display file count and word frequency
- 🔹 Save the database into a backup file
- 🔹 Load and update an existing database
- 🔹 Add new files to the existing database
- 🔹 Dynamic memory allocation
- 🔹 Colorful terminal output

## 🧠 Data Structure

The project uses a 27-index hash table.

The hash table contains:

- Index 0–25 → Words beginning with A–Z
- Index 26 → Words beginning with other characters

Each hash-table index contains a linked list of words.

Each word node stores:

- Word
- File count
- File list

Each file node stores:

- File name
- Word count

## ⚙️ How It Works

1. The program accepts multiple .txt files through command-line arguments.
2. Each file is validated before processing.
3. The contents of the files are read word by word.
4. A hash index is calculated for each word.
5. The word is stored in the corresponding hash-table index.
6. File names and word frequencies are maintained using linked lists.
7. The generated database can be displayed, searched, saved, or updated.

## 📋 Menu Options

The application provides the following operations:

1. Create Database
2. Display Database
3. Save Database
4. Search
5. Update Database
6. Exit

### 1️⃣ Create Database

Creates the inverted database using the validated text files.

The database stores each unique word along with the files in which it occurs and its frequency.

### 2️⃣ Display Database

Displays the complete inverted database in a structured format.

The output contains:

Index | Word | File Count | File Name | Word Count

Example:

Index: 7
Word: hello
File Count: 2
File 1: file1.txt
Word Count: 3
File 2: file2.txt
Word Count: 2

### 3️⃣ Save Database

Saves the complete database into a backup file.

The backup file contains the indexed information required to restore the database later.

### 4️⃣ Search

Allows the user to search for a particular word.

For example:

Enter the word you want to search: hello

The program displays:

- Number of files containing the word
- File names
- Number of occurrences in each file

Example:

Word hello is present in 2 files.

IN FILE: file1.txt, word hello is present 3 times.

IN FILE: file2.txt, word hello is present 2 times.

### 5️⃣ Update Database

Loads an existing backup database and adds a new text file.

The program validates the backup file and the new input file before updating the database.

### 6️⃣ Exit

Exits the application and clears the dynamically allocated database memory.

## 🔐 File Validation

Before creating the database, the program validates the input files.

The following checks are performed:

- ✔️ File name validation
- ✔️ .txt extension validation
- ✔️ File existence
- ✔️ Empty file detection
- ✔️ Duplicate file detection

Only valid files are added to the file list.

## 💾 Database Backup

The database can be stored in a backup file.

The saved database contains information such as:

- Index
- Word
- File Count
- File Name
- Word Count

The backup file can later be loaded using the Update Database option.

## 🏗️ Project Structure

Inverted_search/
│
├── inverted.h
├── inverted.c
├── create.c
├── display.c
├── insertl.c
├── main.c
├── save.c
├── search.c
├── update.c
├── makefile
├── README.md
├── s.txt
├── s1.txt
└── backup.txt

## 📂 File Description

| File | Description |
|------|-------------|
| main.c | Contains the main function and menu-driven interface |
| inverted.h | Contains structures, macros and function declarations |
| inverted.c | Performs file validation and hash-index calculation |
| create.c | Creates the inverted database |
| display.c | Displays the complete database |
| insertl.c | Handles insertion of files into the linked list |
| search.c | Searches for a word in the database |
| save.c | Saves the database into a backup file |
| update.c | Loads and updates an existing database |
| makefile | Compiles and cleans the project |

## 🛠️ Technologies Used

- C Programming
- Data Structures
- Hash Tables
- Linked Lists
- Dynamic Memory Allocation
- File Handling
- String Manipulation
- Command Line Arguments
- Makefile
- Git & GitHub

## 🚀 Compilation

Clone the repository using:

git clone <your-repository-url>

Navigate to the project directory:

cd Inverted_search

Compile the project using the Makefile:

make

## ▶️ How to Run

Run the program by providing text files as command-line arguments:

./inv.exe s.txt s1.txt

Multiple text files can be provided:

./inv.exe file1.txt file2.txt file3.txt

The program first validates the files and displays the validated file names.

## 🧹 Clean the Project

To remove object files and executable files:

make clean

## 🎯 Learning Outcomes

This project provides practical experience with:

- Hash table implementation
- Linked list implementation
- Dynamic memory allocation
- Structures and pointers
- File handling in C
- Command-line arguments
- String processing
- Database creation and updating
- Searching and indexing techniques
- Modular C programming
- Makefile-based compilation

## 🌟 Applications

The concept of inverted indexing can be used in:

- 🔎 Search engines
- 📚 Document indexing systems
- 📄 File search applications
- 🗂️ Document management systems
- 🔍 Text retrieval systems

## 👨‍💻 Author

SHREEVATHSA


