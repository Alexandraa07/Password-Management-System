#include "PasswordEntry.h"
#include <string>

void Add(PasswordEntry P);
void Find(std::string siteCautat);
void LoadFromFile();
void SaveToFile();

int main()
{
    int optiune;
    std::string s, u, p;

    LoadFromFile();
    do
    {
        std::cout << "\n1-ADAUGARE, 2-CAUTARE, 3-IESIRE\nAlege: ";
        std::cin >> optiune;

        switch (optiune)
        {
        case 1:
            std::cout << "Site: ";
            std::cin >> s;
            std::cout << "User: ";
            std::cin >> u;
            std::cout << "Pass: ";
            std::cin >> p;

            {

                PasswordEntry nou(s, u, p);
                Add(nou);
            }
            std::cout << "Parola salvata in RAM!" << std::endl;
            break;

        case 2:
            std::cout << "Ce site cauti?: ";
            std::cin >> s;
            Find(s);
            break;

        case 3:
            std::cout << "Inchidem programul..." << std::endl;
            SaveToFile();
            break;

        default:
            std::cout << "Incearca 1, 2 sau 3." << std::endl;
            break;
        }
    } while (optiune != 3);

    return 0;
}