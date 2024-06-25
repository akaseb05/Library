
# Online Library Management System

This C++ project implements a basic Library Management System. The system provides functionalities for managing books and students in a library, including adding, modifying, searching, listing, issuing, and returning books. Additionally, the system includes functionality for managing rewards.

## Features

### Book Management
- **Add Book**: Allows the user to add a new book to the library database.
- **Modify Book**: Allows the user to modify details of an existing book.
- **Search Book**: Provides functionality to search for a specific book by its book number.
- **List Books**: Lists all the books available in the library along with their details.
- **Delete Book**: Allows the user to delete a book record from the library database.
- **Issue Book**: Manages the issuance of books to students.
- **Return Book**: Manages the return process of issued books.

### Student Management
- **Add Student**: Allows the user to add a new student to the library database.
- **Modify Student**: Allows the user to modify details of an existing student.
- **Search Student**: Provides functionality to search for a specific student by their admission number.
- **List Students**: Lists all the students registered in the library along with their details.
- **Delete Student**: Allows the user to delete a student record from the library database.

### Reward Management
- **Add Reward**: Allows the user to add a new reward to the system.
- **Modify Reward**: Allows the user to modify details of an existing reward.
- **Delete Reward**: Allows the user to delete a reward based on its reward number.
- **List Rewards**: Lists all rewards available in the system along with their details.

## Class Descriptions

### `book`
This class handles all book-related operations:
- `createb()`: Enter data for a new book.
- `showb()`: Display details of a specific book.
- `showlist()`: Display details of all books in list form.
- `assignbno(int x)`: Assign a unique book number.
- `set_q()`: Decrement the quantity of the book.
- `quantity()`: Return the quantity of the book.
- `reset_q()`: Reset the quantity of the book.
- `retbno()`: Return the book number.

### `student`
This class handles all student-related operations:
- `creates()`: Enter data for a new student.
- `shows()`: Display details of a specific student.
- `showlist()`: Display details of all students in list form.
- `settoken(int x)`: Assign a book to a student and set a token.
- `resettoken()`: Reset the token when a book is returned.
- `retbno()`: Return the book number assigned to the student.

### `Reward`
This class handles all reward-related operations:
- Constructor to initialize reward details.
- Getter and setter methods for reward attributes.
- `displayReward()`: Display details of a specific reward.

## How to Use

1. **Compile the Code**: Use a C++ compiler to compile the code. For example:
   ```bash
   g++ -o library_management library_management.cpp
   ```

2. **Run the Program**: Execute the compiled program:
   ```bash
   ./library_management
   ```

3. **Follow the Menu**: The program will present a menu with various options for managing books, students, and rewards. Choose the appropriate option and follow the prompts.

## Dependencies

This project uses standard C++ libraries including:
- `<iostream>` for input and output operations
- `<fstream>` for file handling operations
- `<stdlib.h>` for general-purpose functions
- `<stdio.h>` for standard input and output functions
- `<process.h>` for process control functions
- `<conio.h>` for console input/output operations (specific to certain compilers)
- `<vector>` for using the vector container

## Notes

- Ensure that the necessary permissions are set for creating, reading, and writing to files.
- The code uses file operations to store and retrieve data, so the existence and proper handling of files (`student.bin`, `book1.bin`, `temp.bin`, and `temp1.bin`) are crucial for the proper functioning of the system.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests with improvements and bug fixes.

## License

This project is open-source and available under the MIT License.

---

Video explanation of code: https://drive.google.com/file/d/1JiAhteqsGgR8EgHSyVcC1oLHBBKmPqDY/view?usp=sharing
