#include <memory.h>
#include <stdio.h>

struct chessCell {
    int color; // 0 = black, 1 = white
    char figure[4];
};

void chessPrint(struct chessCell chessState[8][8])
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                printf("\e[47m");
            } else {
                printf("\e[100m");
            }
            if (chessState[i][j].color) {
                printf(" \e[30m%s ", chessState[i][j].figure);
            } else {
                printf(" \e[39m%s ", chessState[i][j].figure);
            }
        }
        printf("\n");
    }
}
int main(int argc, char const* argv[])
{
    // UNICODE CHESS SYMBOLS
    char pawn[4] = "\u265F";
    char knight[4] = "\u265E";
    char bishop[4] = "\u265D";
    char rook[4] = "\u265C";
    char queen[4] = "\u265B";
    char king[4] = "\u265A";
    char empty[4] = " ";

    struct chessCell chessState[8][8];

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            memcpy((chessState[i][j]).figure, empty, sizeof empty);
        }
    }
    for (int i = 0; i < 9; i += 7) {
        memcpy(chessState[i][0].figure, rook, sizeof rook);
        memcpy(chessState[i][1].figure, knight, sizeof knight);
        memcpy(chessState[i][2].figure, bishop, sizeof bishop);
        memcpy(chessState[i][3].figure, queen, sizeof queen);
        memcpy(chessState[i][4].figure, king, sizeof king);
        memcpy(chessState[i][5].figure, bishop, sizeof bishop);
        memcpy(chessState[i][6].figure, knight, sizeof knight);
        memcpy(chessState[i][7].figure, rook, sizeof rook);
    }
    for (int i = 1; i < 7; i += 5) {
        for (int j = 0; j < 8; ++j) {
            memcpy(chessState[i][j].figure, pawn, sizeof pawn);
        }
    }
    for (int j = 0; j < 8; ++j) {
        chessState[0][j].color = 0;
        chessState[1][j].color = 0;
        chessState[6][j].color = 1;
        chessState[7][j].color = 1;
    }

    chessPrint(chessState);
    return 0;
}