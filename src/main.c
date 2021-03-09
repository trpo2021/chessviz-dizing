#include <memory.h>
#include <stdio.h>

typedef struct {
    int color; // 0 = black, 1 = white
    char figure[4];
} chessCell;

typedef chessCell chessField[8][8];

void printChessField(chessField chessState)
{
    printf("   a  b  c  d  e  f  g  h\n");
    for (int i = 0; i < 8; ++i) {
        printf("%d ", i + 1);
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
        printf("\e[0m %d\n", i);
    }
    printf("   a  b  c  d  e  f  g  h\n");
}

void initializeChessField(chessField chessState)
{
    // UNICODE CHESS SYMBOLS
    char pawn[4] = "\u265F";
    char knight[4] = "\u265E";
    char bishop[4] = "\u265D";
    char rook[4] = "\u265C";
    char queen[4] = "\u265B";
    char king[4] = "\u265A";
    char empty[4] = " ";

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
}

void moveChessFigure(chessField chessState, int x1, int y1, int x2, int y2)
{
    memcpy(chessState[x2][y2].figure, chessState[x1][y1].figure, 4);
    chessState[x2][y2].color = chessState[x1][y1].color;

    memcpy(chessState[x1][y1].figure, " ", 4);
}

int coordFromChar(char symb)
{
    char row[] = "abcdefgh";
    for (int i = 0; i < 8; ++i) {
        if (symb == row[i]) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char const* argv[])
{
    chessField chessState;
    initializeChessField(chessState);
    printChessField(chessState);

    FILE* fp;
    char str[32];
    int iter = 0;
    fp = fopen(argv[1], "r");
    while (fp != NULL && (fgets(str, 30, fp))) {
        int x1 = (int)str[1] - 49;
        int y1 = coordFromChar(str[0]);
        int x2 = (int)str[4] - 49;
        int y2 = coordFromChar(str[3]);

        ++iter;
        printf("Move %d: %c%c to %c%c\n", iter, str[0], str[1], str[3], str[4]);
        if (x1 == -1 || x2 == -1 || y1 == -1 || y2 == -1) {
            printf("Error: Incorrect input\n");
            return -1;
        }

        moveChessFigure(chessState, x1, y1, x2, y2);
        printChessField(chessState);
    }

    return 0;
}