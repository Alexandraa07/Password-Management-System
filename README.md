# Password Manager (C++)

## Description
This project is a console-based password manager developed in C++.  
It allows users to securely store and retrieve login credentials for different websites.

The application provides a simple interface for adding and searching stored credentials while ensuring protection through password encryption.

## Features
- Master password authentication before accessing the application
- Add new credentials (website, username, password)
- Search for saved credentials by website
- Basic password encryption and decryption
- Persistent storage using file handling
- Simple console-based interface

## Technologies Used
- C++
- Object-Oriented Programming (OOP)
- STL "map" for efficient credential storage and lookup
- File I/O ("fstream") for saving and loading data
- Basic XOR-based encryption for password protection

## Project Structure
PasswordManager – handles credential storage, encryption/decryption, and file operations
PasswordEntry – represents a single credential entry (website, username, password)
main.cpp – provides the console interface and program flow

## How It Works
1. Launch the program and enter the master password.
       For demo purposes, the default master password is "admin1007"
3.  After successful login, choose from the menu:
       Add a new credential
       Search for stored credentials
       Exit the program
4. Passwords are encrypted before being saved to a file.
5. On exit, all data is saved for future use.

## How to Run

1. Compile the program using a C++ compiler.
Example using g++:
g++ main.cpp PasswordManager.cpp PasswordEntry.cpp -o main

2. Run the program:
./main

3. Enter the master password to access the application.
