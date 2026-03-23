#include <iostream>
#include "PasswordManager.h"

int main()
{
    PasswordManager manager;
    std::string masterPass;

    std::cout << "Introdu master password: ";
    std::cin >> masterPass;

    if (!manager.login(masterPass))
    {
        std::cout << "Parola incorecta! La revedere." << std::endl;
        return 0;
    }

    int option;
    std::string site, user, pass;

    do
    {
        std::cout << "\n1-ADAUGARE  2-CAUTARE  3-IESIRE" << std::endl;
        std::cout << "Alege: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            std::cout << "Site: ";
            std::cin >> site;
            std::cout << "User: ";
            std::cin >> user;
            std::cout << "Pass: ";
            std::cin >> pass;
            manager.addEntry(site, user, pass);
            break;

        case 2:
            std::cout << "Ce site cauti?: ";
            std::cin >> site;
            {
                PasswordEntry e = manager.getEntry(site);
                if (e.getWebsite() != "Inexistent")
                {
                    std::cout << "User: " << e.getUsername() << "\n";
                    std::cout << "Pass: " << e.getPassword() << "\n";
                }
                else
                {
                    std::cout << "Site-ul nu a fost gasit." << std::endl;
                }
            }
            break;

        case 3:
            manager.saveToFile();
            std::cout << "Date salvate. La revedere!" << std::endl;
            break;
        }
    } while (option != 3);

    return 0;
}