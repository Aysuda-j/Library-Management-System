# Library Management System (C)

A command-line Library Management System written in C, built as a first hands-on project to learn structs, file-free in-memory data management, string handling, and real date/time arithmetic.

## Features

- **Add books** — title, author, publication year, and a unique ID
- **Search** — look up books by title, author, publication year, or member ID
- **View availability status** — check whether a specific book is currently borrowed
- **Check out a book** — records the borrowing member's ID, automatically timestamps the checkout, and calculates a 14-day due date
- **Check in a book** — automatically timestamps the return and flags whether it was returned on time or overdue

## Built With

- C (compiled with GCC)
- `<time.h>` for automatic timestamping and due-date calculations
- `<string.h>` for string handling and search matching

## Getting Started

### Prerequisites

- GCC (or any standard C compiler)

### Build & Run

```bash
gcc main.c -o main
./main        # on Windows: main.exe
```

### Usage

Run the program and choose an option from the menu:

```
=== Library Management System ===
1. Add a new book
2. Search for a book
3. View availability
4. Check out a book
5. Check in a book
6. Exit
```

## Project Structure

```
.
├── main.c        # All program logic
└── .gitignore    # Excludes compiled binaries from version control
```

## Possible Future Improvements

- Persist library data to a file so it's saved between runs
- Support editing or deleting existing book records
- Search by book ID in addition to title/author/year/member ID

## Author

**Aysuda** — [@Aysuda-j](https://github.com/Aysuda-j)
