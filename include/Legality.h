#ifndef LEGALITY_H
#define LEGALITY_H

#include "Entities.h"

void rookLegality(ChessGame * game , Move move);
void bishopLegality(ChessGame *game , Move move);
void queenLegality(ChessGame*game , Move move);

#endif