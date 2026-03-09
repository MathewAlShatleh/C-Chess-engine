#include <stdlib.h>
#include "Piece.h"

Piece* initializePieces() {
    Piece* piece = malloc(sizeof *piece);
    if(piece != NULL) {
        piece->type = EMPTY;
        piece->color = NO_COLOR;
        return piece;
    }
return NULL;
}