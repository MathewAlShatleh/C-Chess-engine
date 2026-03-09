#include <stdlib.h>
#include "Move.h"

Move * initializeMove() {
    Move* move = malloc(sizeof *move);
    if(move != NULL) {
        move->moveFrom = 0;
        move->moveTo = 0;
        return move;
    }
return NULL;
}