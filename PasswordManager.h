#include <map>
#include <string>
#include "PasswordEntry.h"

class PasswordManager
{
private:
    std::map<std::string, PasswordEntry> entries;
    std::string masterPasswordHash;
    std::string encrypt(std::string data);
    std::string decrypt(std::string data);

public:
    PasswordManager();
    bool login(std::string inputPass);
    void addEntry(std::string site, std::string user, std::string pass);
    PasswordEntry getEntry(const std::string& site);
    void saveToFile();
    void loadFromFile();
};