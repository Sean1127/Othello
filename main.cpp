#include <iostream>
#include <ctime>
#include "othello.h"

using namespace std;

vector<vector<int> > createBoard()
{
    vector<vector<int> > b(ROWS, vector<int>(COLS, EMPTY));
    b[d][4] = BLACK;
    b[e][3] = BLACK;
    b[e][4] = WHITE;
    b[d][3] = WHITE;
    return b;
}

void initPlayer(Player *player)
{
    player[0] = Player(BLACK, false);
    player[1] = Player(WHITE, true);
}

int main(int argc, char *argv[])
{
    // declaration
    vector<vector<int> > board;
    Player player[2];
    int turn = 0;
    int move;

    // initialization
    board = createBoard();
    initPlayer(player);
    srand(time(NULL));

    // main loop
    while (!Othello::isFull(board)) {
        vector<Move> moves = Othello::getLegalMoves(&board, player[turn].color);
        Othello::print(board);
        if (player[turn].color == BLACK) {
            cout << "BLACK's turn" << endl;
        } else {
            cout << "WHITE's turn" << endl;
        }

        if (player[turn].AI) {
            for (size_t i = 0; i < moves.size(); ++i) {
                char c = 'a';
                cout << i << ": " << (char) (c + moves[i].x) << moves[i].y + 1 << endl;
            }

            // AI algorithm
            move = Othello::MCSPure(board, moves, player[turn].color);
            Othello::makeMove(&board, moves[move], player[turn].color);
            cout << "player" << turn << " plays " << move << endl << endl;
        } else {
            for (size_t i = 0; i < moves.size(); ++i) {
                char c = 'a';
                cout << i << ": " << (char) (c + moves[i].x) << moves[i].y + 1 << endl;
            }
            cout << "player" << turn << " plays " ;

            // user input
            cin >> move;
            cout << endl;
            Othello::makeMove(&board, moves[move], player[turn].color);
        }

        turn = (turn)? 0: 1;
    }
    return 0;
}
