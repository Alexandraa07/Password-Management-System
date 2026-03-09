#include "PasswordManager.h"
#include "PasswordEntry.h"

PasswordManager::PasswordManager()
{
    loadFromFile();
}

void PasswordManager::addEntry(std::string site, std::string user, std::string pass)
{
    std::string parolaCriptata = encrypt(pass);
    PasswordEntry nou(site, user, parolaCriptata);
    entries[site] = nou;
    std::cout << "Datele pentru " << site << " au fost salvate criptat!\n";
}

std::string PasswordManager::encrypt(std::string data)
{
    std::string result = data;
    for (auto i = 0; i < data.size(); i++) {
        result[i] = data[i] + 5;
    }
    return result;
}

std::string PasswordManager::decrypt(std::string data)
{
    std::string result = data;
    for (auto i = 0; i < data.size(); i++) {
        result[i] = data[i] - 5;
    }
    return result;
}

PasswordEntry PasswordManager::getEntry(const std::string& site)
{
    auto it = entries.find(site);
    if (it != entries.end())
    {
        PasswordEntry p = it->second;
        std::string parolaCurata = decrypt(p.Get_Password());
        p.Set_Password(parolaCurata);
        return p;
    }

    return PasswordEntry("nu exista", "", "");
}


bool PasswordManager::login(std::string inputPass)
{
    if (inputPass == "admin1007")
    {
        return true;
    }
    return false;
}

void PasswordManager::saveToFile()
{
    std::ofstream f("date.txt");
    if (!f)
        return;
    for (auto it = entries.begin(); it != entries.end(); it++)
    {
        f << it->second.Get_Website() << " " << it->second.Get_Username() << " " << it->second.Get_Password() << "\n";
    }
    f.close();
}

void PasswordManager::loadFromFile()
{
    std::ifstream f("date.txt");
    if (!f)
        return;

    std::string s, u, p;
    while (f >> s >> u >> p)
    {
        PasswordEntry temp(s, u, p);
        entries[s] = temp;
    }
    f.close();
}