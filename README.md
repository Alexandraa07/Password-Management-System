# Password Manager (C++)

## Description
This project is a console-based password manager developed in C++.  
It allows users to securely store and retrieve login credentials for different websites.

The application provides a simple interface for adding and searching stored credentials while ensuring basic protection through password encryption.

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
- STL 'map' for efficient credential storage and lookup
- File I/O ('fstream') for saving and loading data
- Basic encryption algorithm for password protection

## Project Structure
PasswordManager – handles credential storage, encryption, and file operations  
PasswordEntry – represents a single credential entry (website, username, password)  
Main – provides the user interface and application flow

## How It Works
1. The user launches the program and enters a master password.
2. After successful login, the user can choose from the following options:
   - Add a new credential
   - Search for stored credentials
   - Exit the program
3. Passwords are encrypted before being stored.
4. When the user exits the program, all data is saved to a file.

## How to Run

1. Compile the program using a C++ compiler.
Example using g++:
g++ main.cpp PasswordManager.cpp PasswordEntry.cpp -o passwordManager

2. Run the program:
./passwordManager

3. Enter the master password to access the application.

## Example Usage

Menu options:

1 - Add credential  
2 - Search credential  
3 - Exit  

Example:

Site: github.com  
Username: user123  
Password: myPassword  

The password will be stored in encrypted form.
