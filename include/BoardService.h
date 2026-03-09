#ifndef BOARDSERVICE_H
#define BOARDSERVICE_H

#include "Entities.h"

void startingBoard(Board* board);
Piece* removePiece(int postion , ChessGame* game);
void movePiece(ChessGame * game , Move move);


#endif