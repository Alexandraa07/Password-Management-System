#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class PasswordEntry
{
private:
    std::string website;
    std::string username;
    std::string password;

public:
    PasswordEntry();
    ~PasswordEntry();
    PasswordEntry(std::string website, std::string username, std::string password);
    void Set_Website(std::string website) { this->website = website; }
    void Set_Username(std::string username) { this->username = username; }
    void Set_Password(std::string password) { this->password = password; }
    std::string Get_Website() { return website; }
    std::string Get_Username() { return username; }
    std::string Get_Password() { return password; }
};