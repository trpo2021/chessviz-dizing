#include <libchessviz/chess.h>
#include <memory.h>
#include <stdio.h>

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