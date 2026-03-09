#include <stdlib.h>
#include "ChessGame.h"

ChessGame * initializeGame() {
    ChessGame* game = malloc(sizeof *game);
    if (game != NULL) {
    game->board = NULL;
    game->player1 = NULL;
    game->player2 = NULL;
    game->log[0] = '\0';
    game->Status = NULL;
    for(int i = 0; i<31;i++) {
    game->removedPieces->color = NO_COLOR;
    game->removedPieces->type = EMPTY;
    }
    game->removedPiecesCounter = 0;
    return game;
    }
    return NULL;  
}