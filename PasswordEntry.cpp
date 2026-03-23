#include "PassWordEntry.h"

PasswordEntry::PasswordEntry()
{
    website = "";
    username = "";
    password = "";
}

PasswordEntry::PasswordEntry(const std::string &website, const std::string &username, const std::string &password)
{
    this->website = website;
    this->username = username;
    this->password = password;
}
