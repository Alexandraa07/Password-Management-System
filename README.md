# Password Manager (C++)

## Description

This application is a simple password manager, written in C++.
It can be used by a user to securely store and retrieve credentials (username and password) for websites.

## Features

- Authentication to access the application
- Adding new credentials (website, username, password)
- Searching for credentials by website name
- Simple password encryption/decryption
- Saving credentials to files

## Technologies used

- C++
- Object-oriented programming (OOP)
- STL "map"
- I/O functions

## Project architecture

PasswordManager – managing credentials and file operations
PasswordEntry – representing a set of credentials (website name, username and password)
main.cpp – console interface

## How it works

1. Launch the program and enter the password (for easier use of the application, a password of "admin1007" was considered)
2. After logging in, choose from the menu:
    Add a new credential
    Search stored credentials
    Delete certain credentials
    Exit the program
3. Passwords are encrypted before being saved to a file.
4. Upon exit, all data is saved for later use.

## How to run

1. Compile the program using a C++ compiler.
Example using g++:
g++ main.cpp PasswordManager.cpp PasswordEntry.cpp -o main

2. Run the program:
./main

3. Enter the master password to access the application.
