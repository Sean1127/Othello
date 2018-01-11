#include "othello.h"

Othello::Othello()
{

}

bool Othello::isFull(vector<vector<int> > board)
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }

    return true;
}

vector<Move> Othello::getLegalMoves(vector<vector<int> > *board, int color)
{
    vector<Move> moves;

    for(size_t i = 0; i < ROWS; ++i) {
        for(size_t j = 0; j < COLS; ++j) {
            Move position(j, i);
            if (isLegal(*board, &position, color)) {
                (*board)[i][j] = MOVE;
                moves.push_back(position);
            }
        }
    }
    return moves;
}

void Othello::print(vector<vector<int> > board)
{
    char c = 'a';
    cout << "  ";
    for (size_t i = 0; i < COLS; ++i) {
        cout << (char) (c + i) << " ";
    }
    cout << endl;

    for (size_t i = 0; i < ROWS; ++i) {
        cout << i + 1 << " ";
        for (size_t j = 0; j < COLS; ++j) {
            switch (board[i][j]) {
            case EMPTY:
                cout << "  ";
                break;
            case BLACK:
                cout << "B ";
                break;
            case WHITE:
                cout << "W ";
                break;
            case MOVE:
                cout << "+ ";
                break;
            default:
                break;
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool Othello::isLegal(vector<vector<int> > board, Move *position, int color)
{
    if (board[position->y][position->x] != EMPTY)
        return false;
    if (checkTop(board, position, color))
        return true;
    if (checkBottom(board, position, color))
        return true;
    if (checkLeft(board, position, color))
        return true;
    if (checkRight(board, position, color))
        return true;
    if (checkTopLeft(board, position, color))
        return true;
    if (checkTopRight(board, position, color))
        return true;
    if (checkBottomLeft(board, position, color))
        return true;
    if (checkBottomRight(board, position, color))
        return true;

    return false;
}

void Othello::makeMove(vector<vector<int> > *board, Move move, int color)
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if ((*board)[i][j] == MOVE) {
                (*board)[i][j] = EMPTY;
            }
        }
    }

    for (size_t i = 0; i < move.captured.size(); ++i) {
        (*board)[move.captured[i].y][move.captured[i].x] = color;
    }
    (*board)[move.y][move.x] = color;
}

/*
 * **************************************************************************************
 * dirty game check functions
 */
bool Othello::checkTop(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->y == 0)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->y - 1; i >= 0; --i) {
        if (board[i][pos->x] == enemy) {
            captured.push_back(Move(pos->x, i));
            enemyDisk = true;
        } else if (board[i][pos->x] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}

bool Othello::checkBottom(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->y == ROWS - 1)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->y + 1; i < ROWS; ++i) {
        if (board[i][pos->x] == enemy) {
            captured.push_back(Move(pos->x, i));
            enemyDisk = true;
        } else if (board[i][pos->x] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}

bool Othello::checkLeft(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->x == 0)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->x - 1; i >= 0; --i) {
        if (board[pos->y][i] == enemy) {
            captured.push_back(Move(i, pos->y));
            enemyDisk = true;
        } else if (board[pos->y][i] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}

bool Othello::checkRight(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->x == COLS - 1)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->x + 1; i < COLS; ++i) {
        if (board[pos->y][i] == enemy) {
            captured.push_back(Move(i, pos->y));
            enemyDisk = true;
        } else if (board[pos->y][i] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}

bool Othello::checkTopLeft(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->x == 0 && pos->y == 0)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->x - 1, j = pos->y - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[j][i] == enemy) {
            captured.push_back(Move(i, j));
            enemyDisk = true;
        } else if (board[j][i] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}

bool Othello::checkTopRight(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->x == COLS - 1 && pos->y == 0)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->x + 1, j = pos->y - 1; i < COLS && j >= 0; ++i, --j) {
        if (board[j][i] == enemy) {
            captured.push_back(Move(i, j));
            enemyDisk = true;
        } else if (board[j][i] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}

bool Othello::checkBottomLeft(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->x == 0 && pos->y == ROWS - 1)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->x - 1, j = pos->y + 1; i >= 0 && j < ROWS; --i, ++j) {
        if (board[j][i] == enemy) {
            captured.push_back(Move(i, j));
            enemyDisk = true;
        } else if (board[j][i] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}

bool Othello::checkBottomRight(vector<vector<int> > board, Move *pos, int ally)
{
    if (pos->x == COLS - 1 && pos->y == ROWS - 1)
        return false;

    int enemy = (ally == BLACK)? WHITE: BLACK;
    bool enemyDisk = false;
    bool allyDisk = false;
    vector<Move> captured;

    for (int i = pos->x + 1, j = pos->y + 1; i < COLS && j < ROWS; ++i, ++j) {
        if (board[j][i] == enemy) {
            captured.push_back(Move(i, j));
            enemyDisk = true;
        } else if (board[j][i] == ally) {
            allyDisk = true;
            break;
        } else {
            captured.clear();
            break;
        }
    }

    if (enemyDisk && allyDisk) {
        for (size_t i = 0; i < captured.size(); ++i) {
            pos->captured.push_back(captured[i]);
        }
        return true;
    }

    return false;
}
/*
 * **************************************************************************************
 */

// pure monte carlo method
int Othello::MCSPure(vector<vector<int> > board, vector<Move> moves, int color)
{
    vector<double> score;
    double bestScore = 0.0;
    int move;

    for (size_t i = 0; i < moves.size(); ++i) {
        double win = 0;

        // almost random game
        for (int j = 0; j < N; ++j) {
            vector<vector<int> > localBoard = board;
            makeMove(&localBoard, moves[i], color);
            int localColor = (color == BLACK)? WHITE: BLACK;
            int allyDisk = 0;
            int enemyDisk = 0;

            while (!Othello::isFull((localBoard))) {
                vector<Move> localMoves = Othello::getLegalMoves(&localBoard, localColor);
                if (localMoves.empty()) {
                    break;
                }
                move = rand() % localMoves.size();
                Othello::makeMove(&localBoard, localMoves[move], localColor);
                localColor = (localColor == BLACK)? WHITE: BLACK;
            }

            for (int m = 0; m < ROWS; ++m) {
                for (int n = 0; n < COLS; ++n) {
                    int enemyColor = (color == BLACK)? WHITE: BLACK;
                    allyDisk += (localBoard[m][n] == color)? 1: 0;
                    enemyDisk += (localBoard[m][n] == enemyColor)? 1: 0;
                }
            }
            win += (allyDisk > enemyDisk)? 1: 0;
        }

        cout << ". ";
        cout << flush;
        score.push_back(win/N);
    }
    cout << endl;

    for (size_t i = 0; i < moves.size(); ++i) {
        if (score[i] > bestScore) {
            bestScore = score[i];
            move = i;
        }
    }
    return move;
}

int Othello::UCT(vector<vector<int> > board, vector<Move> moves, int color)
{
    int move;

    for (int i = 0; i < N; ++i) {
        // selection
        // expansion
        // simulation
        // backward propagation
    }

    return move;
}
