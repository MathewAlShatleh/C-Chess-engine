#include <stdlib.h>
#include "GameService.h"
#include "Player.h"
#include "ChessGame.h"
#include "Board.h"

int main() {
    ChessGame *game = initializeGame();
    if(game == NULL) return -1;
    game->player1 = initializePlayers();
    game->player2 = initializePlayers();
    game->board = initializeBoard();
    if(game->player1 == NULL || game->player2 == NULL || game->board == NULL) return -1;
    startGame(game);
    return 0;
}