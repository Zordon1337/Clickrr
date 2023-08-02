
#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Utils.h"
#include <filesystem>

using namespace std;

int main()
{
    int money = 0;
    int upgradecost = 75;
    int upgradelevel = 1;
    int uilvl = 0;

   
    
    while (true)
    {
        if (uilvl == 0)
        {
            cout << "Welcome in Clickrr, clicker that will even work on 20 years old pc" << endl;
            cout << "[LEFT SHIFT] Load Save Game" << endl;
            cout << "[RIGHT SHIFT] Start from beginning" << endl;
            if (GetAsyncKeyState(VK_LSHIFT))
            {                               
                if (Utils::SaveGame::CheckIfSaveExists())
                {
                    money = Utils::SaveGame::ReadDouble("money");
                    upgradelevel = Utils::SaveGame::ReadDouble("upgradelevel");
                    upgradecost = Utils::SaveGame::ReadDouble("upgradecost");
                    uilvl = 1;
                }
                else {
                    cout << "Save doesn't exist, restart game and select 'Start from beginning'" << endl;
                }
            }
            if (GetAsyncKeyState(VK_RSHIFT))
            {
                uilvl = 1;
            }
        }
        else {
            cout << "\n\nMoney: " << money << endl;
            cout << "Upgrade cost: " << upgradecost << endl;
            cout << "Upgrade level: " << upgradelevel << endl;
            cout << "\n[Right SHIFT] Upgrade" << endl;
            cout << "[SPACE] CLICK" << endl;
            cout << "[LEFT SHIFT] SAVE" << endl;
            cout << "[TAB] SAVE AND EXIT" << endl;
            if (GetAsyncKeyState(VK_SPACE))
            {
                money = money + 2 * (upgradelevel * 2);

            }

            if (GetAsyncKeyState(VK_RSHIFT))
            {
                if (upgradecost <= money)
                {
                    money = money - upgradecost;
                    upgradecost = upgradecost * 1.5;
                    upgradelevel = upgradelevel + 1;
                }

            }
            if (GetAsyncKeyState(VK_LSHIFT))
            {
                Utils::SaveGame::Save(money, upgradelevel, upgradecost);
            }
            if (GetAsyncKeyState(VK_TAB))
            {
                Utils::SaveGame::Save(money, upgradelevel, upgradecost);
                return 0;
            }
            
            
        }
        Sleep(100);
        std::system("cls");
        

    }
}

