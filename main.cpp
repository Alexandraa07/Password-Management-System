#include <iostream>
#include "PasswordManager.h"

int main()
{
    PasswordManager manager;
    std::string masterPass;

    std::cout << "Introdu parola pentru acces: ";
    std::cin >> masterPass;

    if (!manager.login(masterPass))
    {
        std::cout << "Acces respins! Parola gresita.\n";
        return 0;
    }

    int optiune;
    std::string s, u, p;

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
            manager.addEntry(s, u, p);
            break;

        case 2:
            std::cout << "Ce site cauti?: ";
            std::cin >> s;

            {
                PasswordEntry gasit = manager.getEntry(s);
                if (gasit.Get_Website() != "Inexistent")
                {
                    std::cout << "User: " << gasit.Get_Username() << "\n";
                    std::cout << "Pass: " << gasit.Get_Password() << "\n";
                }
                else
                {
                    std::cout << "Site-ul nu a fost gasit.\n";
                }
            }
            break;

        case 3:
            manager.saveToFile();
            std::cout << "Date salvate. La revedere!\n";
            break;
        }
    } while (optiune != 3);

    return 0;
}