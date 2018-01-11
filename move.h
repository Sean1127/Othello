#ifndef MOVE_H
#define MOVE_H

#include <vector>

using namespace std;

class Move
{
public:
    Move(int x, int y);
    int x;
    int y;
    vector<Move> captured;
};

#endif // MOVE_H
