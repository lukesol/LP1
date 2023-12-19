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
    short pts; //!< Accumulated points of a turn in progress.
    short n_try; //!< # of dice roll of a turn in progress.
};

class player
{
private:
    string m_name;
    string m_name;
public:
    player(/* args */);
    ~player();
};

player::player(/* args */)
{
}

player::~player()
{
}




#endif