#include "PasswordEntry.h"

std::vector<PasswordEntry> entries;

void Add(PasswordEntry P)
{
    entries.push_back(P);
}

void Find(std::string siteCautat)
{
    for (auto i = 0; i < entries.size(); i++)
    {
        if (siteCautat == entries[i].Get_Website())
        {
            std::cout << "--- DATE GASITE ---" << std::endl;
            std::cout << "User: " << entries[i].Get_Username() << std::endl;
            std::cout << "Pass: " << entries[i].Get_Password() << std::endl;
            return;
        }
    }
    std::cout << "--- DATELE NU AU FOST GASITE ---" << std::endl;
}

void SaveToFile()
{
    std::ofstream f("date.txt");
    for (auto i = 0; i < entries.size(); i++)
    {
        f << entries[i].Get_Website() << " "
          << entries[i].Get_Username() << " "
          << entries[i].Get_Password() << "\n";
    }
    f.close();
    std::cout << "Datele au fost salvate pe disk!\n";
}

void LoadFromFile()
{
    std::ifstream f("date.txt");
    if (!f)
        return;

    std::string s, u, p;
    while (f >> s >> u >> p)
    {
        PasswordEntry temporar(s, u, p);
        entries.push_back(temporar);
    }
    f.close();
}