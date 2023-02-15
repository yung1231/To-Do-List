# To-Do List Application in C++
This is a simple to-do list application written in C++. The program allows the user to add, edit, view, and remove tasks from a list, as well as save the list to a file. The tasks are saved in a text file with the user's name as the file name.

## Getting Started
These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites
To run this program, you need to have the `g++` compiler and `make` installed in your system.
- gcc version 7.5.0
- Make 4.1

### Compilation and Running
```bash
g++ main.cpp -o main
./main
```

or

```bash
make
./main
```

## Features
1. Add task：Add a task to the To-Do list.
2. View tasks：View all tasks in the To-Do list.
3. Remove task：Remove a task from the To-Do list.
4. Edit task：Edit an existing task in the To-Do list.
5. Quit：Quit the application and save the To-Do list to a file.

## Limitations
The program is a simple To-Do list application with limited functionality. It is not designed to handle multiple users or complex task management. The file persistence feature only saves the list to a file on the same machine, and does not provide any synchronization between different machines or platforms.

## License
This project is licensed under the Apache 2.0 License