#define CTEST_MAIN

#include <ctest.h>
#include <libchessviz/chess.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

//////////////////////////////////////////////////////

CTEST(InitializeChessBoard, test1) {
    chessField chessState;
    initializeChessField(chessState);

    ASSERT_EQUAL(0, chessState[0][0].color);
    ASSERT_STR("\u265C", chessState[0][0].figure);
}

CTEST(InitializeChessBoard, test2) {
    chessField chessState;
    initializeChessField(chessState);
    
    ASSERT_STR(" ", chessState[4][5].figure);
}

CTEST(InitializeChessBoard, test3) {
    chessField chessState;
    initializeChessField(chessState);

    ASSERT_EQUAL(1, chessState[7][2].color);
    ASSERT_STR("\u265D", chessState[7][2].figure);
}

CTEST(InitializeChessBoard, test4) {
    chessField chessState;
    initializeChessField(chessState);

    ASSERT_EQUAL(1, chessState[7][7].color);
    ASSERT_STR("\u265C", chessState[7][7].figure);
}

//////////////////////////////////////////////////////

CTEST(moveChessFigure, test1){
    chessField chessState;
    initializeChessField(chessState);

    moveChessFigure(chessState, 0, 0, 4, 5);

    ASSERT_EQUAL(0, chessState[4][5].color);
    ASSERT_STR("\u265C", chessState[4][5].figure);

    ASSERT_STR(" ", chessState[0][0].figure);
}

CTEST(moveChessFigure, test2){
    chessField chessState;
    initializeChessField(chessState);

    moveChessFigure(chessState, 7, 2, 4, 5);

    ASSERT_EQUAL(1, chessState[4][5].color);
    ASSERT_STR("\u265D", chessState[4][5].figure);

    ASSERT_STR(" ", chessState[7][2].figure);
}

CTEST(moveChessFigure, test3){
    chessField chessState;
    initializeChessField(chessState);

    moveChessFigure(chessState, 7, 7, 2, 2);

    ASSERT_EQUAL(1, chessState[2][2].color);
    ASSERT_STR("\u265C", chessState[2][2].figure);

    ASSERT_STR(" ", chessState[7][7].figure);
}

//////////////////////////////////////////////////////

/*CTEST(moveChessFigure, test1){
    chessField chessState;
    initializeChessField(chessState);

    moveChessFigure(chessState, 7, 7, 2, 2);

    ASSERT_EQUAL(1, chessState[2][2].color);
    ASSERT_STR("\u265C", chessState[2][2].figure);

    ASSERT_STR(" ", chessState[7][7].figure);
}

CTEST(moveChessFigure, test2){
    chessField chessState;
    initializeChessField(chessState);

    moveChessFigure(chessState, 7, 7, 2, 2);

    ASSERT_EQUAL(1, chessState[2][2].color);
    ASSERT_STR("\u265C", chessState[2][2].figure);

    ASSERT_STR(" ", chessState[7][7].figure);
}

CTEST(moveChessFigure, test3){
    chessField chessState;
    initializeChessField(chessState);

    moveChessFigure(chessState, 7, 7, 2, 2);

    ASSERT_EQUAL(1, chessState[2][2].color);
    ASSERT_STR("\u265C", chessState[2][2].figure);

    ASSERT_STR(" ", chessState[7][7].figure);
}
*/