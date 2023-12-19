#ifndef PLAYER_H //definição de cabeçalho
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

struct TurnInfo {
    string word;
    bool win; 
};

class Player
{
private:
    string m_name;
    TurnInfo game_played;
public:
    Player() = default;

    void set_name(string name){ m_name = name; };
    void set_game_played(TurnInfo play){ game_played.win = play.win; game_played.word = play.word; };
    TurnInfo get_turn_info(){ return game_played; };
    string get_name(){ return m_name; };
};


#endif