#include "PasswordManager.h"
#include <fstream>
#include <iostream>

std::string PasswordManager::simpleHash(const std::string &input)
{
    unsigned long hash = 0;
    for (char c : input)
        hash = (hash * 31 + c) % 1000000;
    return std::to_string(hash);
}

std::string PasswordManager::encrypt(const std::string &data)
{
    std::string result = data;
    for (size_t i = 0; i < data.size(); ++i)
        result[i] = data[i] ^ masterPasswordHash[i % masterPasswordHash.size()];
    return result;
}

std::string PasswordManager::decrypt(const std::string &data)
{
    return encrypt(data);
}

PasswordManager::PasswordManager()
{
    loadFromFile();
    if (masterPasswordHash.empty())
        masterPasswordHash = simpleHash("admin1007"); // parola default pentru test
}

void PasswordManager::setMasterPassword(const std::string &newPass)
{
    masterPasswordHash = simpleHash(newPass);
}

bool PasswordManager::login(const std::string &inputPass)
{
    return simpleHash(inputPass) == masterPasswordHash;
}

void PasswordManager::addEntry(const std::string &site, const std::string &user, const std::string &pass)
{
    std::string encrypted = encrypt(pass);
    entries[site] = PasswordEntry(site, user, encrypted);
    std::cout << "Datele pentru " << site << " au fost salvate criptat!" << std::endl;
}

PasswordEntry PasswordManager::getEntry(const std::string &site)
{
    auto it = entries.find(site);
    if (it != entries.end())
    {
        PasswordEntry copy = it->second;
        copy.setPassword(decrypt(copy.getPassword()));
        return copy;
    }
    return PasswordEntry("Inexistent", "", "");
}

void PasswordManager::saveToFile()
{
    std::ofstream f("passwords.txt");
    if (!f)
        return;

    f << masterPasswordHash << std::endl;

    for (auto &pair : entries)
    {
        f << pair.second.getWebsite() << " "
          << pair.second.getUsername() << " "
          << pair.second.getPassword() << "\n";
    }

    f.close();
}

void PasswordManager::loadFromFile()
{
    std::ifstream f("passwords.txt");
    if (!f)
        return;

    entries.clear();

    std::string line;
    if (std::getline(f, line))
        masterPasswordHash = line;

    std::string site, user, pass;
    while (f >> site >> user >> pass)
    {
        entries[site] = PasswordEntry(site, user, pass);
    }

    f.close();
}