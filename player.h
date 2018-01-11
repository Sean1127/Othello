#ifndef PLAYER_H
#define PLAYER_H

#include "type.h"

class Player
{
public:
    Player(int color = BLACK, bool AI = false);
    bool AI;
    int color;
};

#endif // PLAYER_H
