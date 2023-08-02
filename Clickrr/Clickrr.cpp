
#include <iostream>
#include <Windows.h>
#include <fstream>
#include "Utils.h"
#include <filesystem>
// moved here because OptionalMultipler couldn't access as it was in main function before
int money = 0;
int upgradecost = 75;
int upgradelevel = 1;
int uilvl = 0;

using namespace std;
double OptionalMultipler()
{
    // i made it because for example game after +100k upgrade cost is starting to be unplayable kinda because to get for ex for next upgrade you need to
    // hold space for like ~~3 minutes and later probably it will be worse so i made it, i don't need to explain how it works just look at the code
    // and you will understand everything probably
    
    if (upgradecost <= 100000 && upgradecost >= 50000)
    {
        return 12.5;
    }
    if (upgradecost <= 250000 && upgradecost >= 100000)
    {
        return 15;
    }
    if (upgradecost >= 300000 && upgradecost <= 500000)
    {
        return 16.9;
    }
    if (upgradecost >= 500000 && upgradecost <= 750000)
    {
        return 110;
    }
    if (upgradecost >= 750000 && upgradecost <= 1500000)
    {
        return 125;
    }
    if (upgradecost >= 1500000 && upgradecost <= 3000000)
    {
        return 150;
    }
    if (upgradecost >= 3000000 && upgradecost <= 5000000)
    {
        return 175;
    }
    if (upgradecost >= 5000000 && upgradecost <= 7500000)
    {
        return 200;
    }
    if (upgradecost >= 7500000 && upgradecost <= 10000000)
    {
        return 225;
    }
    if (upgradecost >= 10000000 && upgradecost <= 25000000)
    {
        return 250;
    }
    if (upgradecost >= 25000000 && upgradecost <= 50000000)
    {
        return 275;
    }
    if (upgradecost >= 50000000 && upgradecost <= 100000000)
    {
        return 300;
    }
    if (upgradecost >= 100000000 && upgradecost <= 250000000)
    {
        return 325;
    }
    if (upgradecost >= 250000000 && upgradecost <= 500000000)
    {
        return 350;
    }
    if (upgradecost >= 500000000 && upgradecost <= 750000000)
    {
        return 375;
    }
    if (upgradecost >= 750000000)
    {
        return 400;
    }
    return 1;
}
int main()
{
    
    SetConsoleTitleA("Clickrr v1.1");

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
                    cout << "Save doesn't exist" << endl;
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
            cout << "Bonus multipler: " << OptionalMultipler() << endl;
            cout << "\n[Right SHIFT] Upgrade" << endl;
            cout << "[SPACE] CLICK" << endl;
            cout << "[LEFT SHIFT] SAVE" << endl;
            cout << "[TAB] SAVE AND EXIT" << endl;
            if (GetAsyncKeyState(VK_SPACE))
            {
                money = money + 2 * (upgradelevel * 2) * OptionalMultipler() * 2;

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

