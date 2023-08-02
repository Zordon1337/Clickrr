#include "json.hpp"
#include <fstream>

namespace Utils {
    namespace SaveGame {
        using namespace nlohmann;
        void Save(double money, double upgradelevel, double upgradecost)
        {
            json savegame;
            savegame["money"] = money;
            savegame["upgradelevel"] = upgradelevel;
            savegame["upgradecost"] = upgradecost;
            std::ofstream file("save.json");
            file << savegame.dump(4);
        }
        double ReadDouble(std::string name)
        {
            std::ifstream file("save.json");
            json data;
            file >> data;
            return data[name];
        }
        bool ReadBool(std::string name)
        {
            std::ifstream file("save.json");
            json data;
            file >> data;
            return data[name];
        }

        bool CheckIfSaveExists()
        {
            std::ifstream file("save.json");
            if (!file)            
                return false;    
            else                 
                return true;     
        }
    }
}