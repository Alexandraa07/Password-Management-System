# Password Manager (C++)

## Description
This application is a simple password manager made in C++.  
It can be used by a user for secure storage and search of credentials (username and password) for websites.

## Features
- Authentication to gain access to the application
- Add new credentials (website, username, password)
- Search credentials by name of a website
- Simple passwords encryption/decryption
- Saving credentials to files
- Simple console application

## Technologies Used
- C++
- Object Oriented Programming (OOP)
- STL "map"
- File I/O functions (fstream)
- Simple password encryption (XOR)

## Project Architecture
PasswordManager – credentials management and file operations
PasswordEntry – representation of a set of credentials (website name, username and password)
main.cpp – console interface

## How It Works
1. Launch the program and enter the master password.
3.  After successful login, choose from the menu:
       Add a new credential
       Search for stored credentials
       Delete certain credentials
       Exit the program
5. Passwords are encrypted before being saved to a file.
6. On exit, all data is saved for future use.

## How to Run

1. Compile the program using a C++ compiler.
Example using g++:
g++ main.cpp PasswordManager.cpp PasswordEntry.cpp -o main

2. Run the program:
./main

3. Enter the master password to access the application.
