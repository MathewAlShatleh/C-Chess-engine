#ifndef GAMESERVICE_H
#define GAMESERVICE_H

#include "Entities.h"

    void startGame(ChessGame *game);
    void endGame(ChessGame *game);
    void endTurn(ChessGame *game);
    char *checkGameStatus(ChessGame *game);
    int get_String_Size (char String[]);

#endif