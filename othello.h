#ifndef OTHELLO_H
#define OTHELLO_H

#include <iostream>
#include "player.h"

#define N 200
#define ROWS 8
#define COLS 8

class Othello
{
public:
    Othello();

    static bool isFull(vector<vector<int> > board);

    static bool isEndGame(vector<vector<int> > board);

    static bool isEarlyGame(vector<vector<int> > board);

    static bool isLegal(vector<vector<int> > board, Move *position, int color);

    static vector<Move> getLegalMoves(vector<vector<int> > *board, int color);

    static void print(vector<vector<int> > board);

    static void makeMove(vector<vector<int> > *board, Move move, int color);

    static int win(vector<vector<int> > board, int color);

    static int MCSPure(vector<vector<int> > board, vector<Move> moves, int color);

    static int UCT(vector<vector<int> > board, vector<Move> moves, int color);

    static int brute(vector<vector<int> > board, vector<Move> moves, int color);

    static bool bruteRecursive(vector<vector<int> > board, int color);

    static bool checkTop(vector<vector<int> > board, Move *pos, int ally);

    static bool checkBottom(vector<vector<int> > board, Move *pos, int ally);

    static bool checkLeft(vector<vector<int> > board, Move *pos, int ally);

    static bool checkRight(vector<vector<int> > board, Move *pos, int ally);

    static bool checkTopLeft(vector<vector<int> > board, Move *pos, int ally);

    static bool checkTopRight(vector<vector<int> > board, Move *pos, int ally);

    static bool checkBottomLeft(vector<vector<int> > board, Move *pos, int ally);

    static bool checkBottomRight(vector<vector<int> > board, Move *pos, int ally);
};

#endif // OTHELLO_H
