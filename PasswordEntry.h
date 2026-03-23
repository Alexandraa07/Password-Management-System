#pragma once
#include <string>

class PasswordEntry {
private:
    std::string website;
    std::string username;
    std::string password; 

public:
    PasswordEntry();
    PasswordEntry(const std::string& website, const std::string& username, const std::string& password);

    void setWebsite(const std::string& website) { this->website = website; }
    void setUsername(const std::string& username) { this->username = username; }
    void setPassword(const std::string& password) { this->password = password; }

    std::string getWebsite() const { return website; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
};