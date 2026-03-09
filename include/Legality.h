#ifndef LEGALITY_H
#define LEGALITY_H

#include "Entities.h"

void pawnLegality(ChessGame *game, Move move);
void rookLegality(ChessGame *game, Move move);
void bishopLegality(ChessGame *game, Move move);
void queenLegality(ChessGame *game, Move move);
void knightLegality(ChessGame *game, Move move);
void kingLegality(ChessGame *game, Move move);

#endif