#pragma once

#ifndef CHESS_H
#define CHESS_H

typedef struct {
    int color; // 0 = black, 1 = white
    char figure[4];
} chessCell;

typedef chessCell chessField[8][8];

void printChessField(chessField chessState);

void initializeChessField(chessField chessState);

void moveChessFigure(chessField chessState, int x1, int y1, int x2, int y2);

#endif