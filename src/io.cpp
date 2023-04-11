#include "io.h"
#include <fstream>
#include <string>
#include "player.h"

long long encode(const std::string &s){         // Generate the hash code of the player info.
    long long sum = 0;
    for(auto c:s){
        sum = (sum*HASH+c)%MOD;
    }
    return sum;
}

int saveToFile(const Player& player){       // Save the player info into gameData.dat
    std::ofstream out("./gameData.dat");
    if(!out) return 1;              // Fail to open data file.
    auto wealth = player.getWealth(), bomb = player.getBombNum();
    auto appearance = player.getAppearance();
    auto score = player.getScore();
    out << wealth << "\n" << bomb << "\n" << appearance << "\n" << score << "\n";

    std::string info = std::to_string(wealth)+std::to_string(bomb)+appearance+std::to_string(score);          // Join the items into a string
    long long sum = encode(info);           // Get the hash sum.
    out << sum;

    out.close();
    return 0;           // Save successfully.
}

int loadFromFile(Player& player){
    std::ifstream in("./gameData.dat");
    if(!in) return 1;           // Fail to open data file.
    int wealth, bomb;
    char appearance;
    int score;
    long long data_sum, cur_sum;
    in >> wealth >> bomb >> appearance >> score >> data_sum;

    std::string info = std::to_string(wealth)+std::to_string(bomb)+appearance+std::to_string(score);          // Join the items into a string
    cur_sum = encode(info);
    if(cur_sum != data_sum) return 2;           // Cannot pass hash validation. Data is incorrect.

    player.setWealth(wealth);
    player.setBombNum(bomb);
    player.setAppearance(appearance);
    player.setScore(score)

    return 0;           // Load successfully.
    
}

void flush(){
    for(int i=0;i<50;i++){
        std::cout<<std::endl;
    }
}
