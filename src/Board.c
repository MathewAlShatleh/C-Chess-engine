#include <stdlib.h>
#include "Board.h"

Board * initializeBoard() {
    Board *board = malloc(sizeof *board);
    if(board == NULL) return NULL;
    for(int i = 0; i< 64;i++){
        board->boardPositions[i].color = NO_COLOR;
        board->boardPositions[i].type = EMPTY;
    }
    return board;
}