#include "PasswordEntry.h"

PasswordEntry::PasswordEntry()
{
    this->website = "";
    this->username = "";
    this->password = "";
}

PasswordEntry::PasswordEntry(const std::string &website, const std::string &username, const std::string &password)
{
    this->website = website;
    this->username = username;
    this->password = password;
}

void PasswordEntry::setWebsite(const std::string &website)
{
    this->website = website;
}

void PasswordEntry::setUsername(const std::string &username)
{
    this->username = username;
}

void PasswordEntry::setPassword(const std::string &password)
{
    this->password = password;
}

std::string PasswordEntry::getWebsite() const
{
    return website;
}

std::string PasswordEntry::getUsername() const
{
    return username;
}

std::string PasswordEntry::getPassword() const
{
    return password;
}