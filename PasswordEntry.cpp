#include "PassWordEntry.h"

PasswordEntry::PasswordEntry()
{
    website = "";
    username = "";
    password = "";
}

PasswordEntry::~PasswordEntry() {}

PasswordEntry::PasswordEntry(std::string website, std::string username, std::string password)
{
    this->website = website;
    this->username = username;
    this->password = password;
}
