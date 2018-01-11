#ifndef OTHELLO_H
#define OTHELLO_H

#include <iostream>
#include "player.h"

#define N 100
#define ROWS 8
#define COLS 8

class Othello
{
public:
    Othello();

    static bool isFull(vector<vector<int> > board);

    static vector<Move> getLegalMoves(vector<vector<int> > *board, int color);

    static void print(vector<vector<int> > board);

    static bool isLegal(vector<vector<int> > board, Move *position, int color);

    static void makeMove(vector<vector<int> > *board, Move move, int color);

    static bool checkTop(vector<vector<int> > board, Move *pos, int ally);

    static bool checkBottom(vector<vector<int> > board, Move *pos, int ally);

    static bool checkLeft(vector<vector<int> > board, Move *pos, int ally);

    static bool checkRight(vector<vector<int> > board, Move *pos, int ally);

    static bool checkTopLeft(vector<vector<int> > board, Move *pos, int ally);

    static bool checkTopRight(vector<vector<int> > board, Move *pos, int ally);

    static bool checkBottomLeft(vector<vector<int> > board, Move *pos, int ally);

    static bool checkBottomRight(vector<vector<int> > board, Move *pos, int ally);

    static int MCSPure(vector<vector<int> > board, vector<Move> moves, int color);

    static int UCT(vector<vector<int> > board, vector<Move> moves, int color);
};

#endif // OTHELLO_H
