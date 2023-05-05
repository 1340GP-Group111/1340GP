#include <fstream>
#include <string>
#include <iostream>
#include "io.h"
#include "player.h"

long long encode(const std::string &s){         // Generate the hash code of the player info.
    long long sum = 0;
    for(auto c:s){
        sum = (sum*HASH+c)%MOD;      //use hash code to prtect the data
    }
    return sum;
}

int saveToFile(const Player& player){       // Save the player info into gameData.dat
    std::ofstream out("./gameData.dat");  //set up a dat file
    if(!out) return 1;              // Fail to open data file.
    auto wealth = player.getWealth(), bomb = player.getBombNum(),oxygen=player.getOxygen(),damage=player.getDamage();
    auto appearance = player.getAppearance();
    out << wealth << "\n" << bomb << "\n" << appearance << "\n"<<damage<<"\n"<<oxygen;  //file output

//    std::string info = std::to_string(wealth)+std::to_string(bomb)+appearance+std::to_string(damage)+std::to_string(oxygen);          // Join the items into a string
//    long long sum = encode(info);           // Get the hash sum.
//    out << sum;

    out.close();
    return 0;           // Save successfully.
}

int loadFromFile(Player& player){
    //open the file
    std::ifstream in("./gameData.dat");
    if(!in) return 1;           // Fail to open data file.
    int wealth, bomb, damage, oxygen;
    //define variables to store the game data
    char appearance;
    // uses char variable to store player's appearance
    long long data_sum, cur_sum;
    in >> wealth >> bomb >> appearance  >> damage >> oxygen >> data_sum;

//    std::string info = std::to_string(wealth)+std::to_string(bomb)+appearance+std::to_string(damage)+std::to_string(oxygen);          // Join the items into a string
//    cur_sum = encode(info);
//    if(cur_sum != data_sum) return 2;           // Cannot pass hash validation. Data is incorrect.

    player.setWealth(wealth);
    //load previuos wealth
    player.setBombNum(bomb);
    //load previuos bomb numbers
    player.setAppearance(appearance);
    //load previuos appearance
    player.setDamage(damage);
    //load previuos damage
    player.setOxygen(oxygen);
    //load previuos oxygen number

    return 0;           // Load successfully.
    
}

void flush(){           // refresh the interface
    for(int i=0;i<50;i++){
        std::cout<<std::endl;
    }
}
