#include <stdlib.h>
#include <stdio.h>
#include "Entities.h"

 int get_String_Size (char String[]) {
    int i = 0;
    while(String[i] != '\0') {
        i++;
    }
    return i;
}

char *checkGameStatus(ChessGame *game) {
     if(game == NULL) {
        return "Game doesn't exist!";
    }
    if(game->board == NULL) {
        game->Status = "Board doesn't exsit!";
        return game->Status;
    }
    if(game->player1 == NULL){
        game->Status = "Player1 doesn't exist!";
        return game->Status;
    }
    if(game->player2 == NULL) {
        game->Status = "player2 doesn't exist!";
        return game->Status;
    }
    return NULL;
}


void startGame (ChessGame *game) {
 char *status = checkGameStatus(game);
if(status != NULL) {
 printf("%s\n" , status);
 return;
}
    int size1 = get_String_Size(game->player1->playerName);
    int size2 = get_String_Size(game->player2->playerName);
    if(size1 > 12 || size1 < 2) {
        game->Status = "player Name should consist of 2 to 12 characters";
        return;
    }
    if(size2 > 12 || size2 < 2) {
        game->Status = "player Name should consist of 2 to 12 characters";
        return;
    }
    game->currentPlayerIdx = rand()%2;
    game->player1->actionCount = 0;
    game->player2->actionCount = 0;
    game->Status = "Game has Started";
   if(game->currentPlayerIdx == 0) {
   snprintf(game->log, 256, "%s starts!" , game->player1->playerName);
   } else snprintf(game->log, 256, "%s starts!" , game->player2->playerName);
}
void endGame (ChessGame *game) {
checkGameStatus(game);

}

void endTurn(ChessGame *game) {
char *status = checkGameStatus(game);
if(status != NULL) {
 printf("%s\n" , status);
 return;
}
if(game->currentPlayerIdx == 0) {
    if(game->player1->actionCount == 1) {
        game->currentPlayerIdx = 1;
        game->player1->actionCount = 0;
    }
} else{
    if(game->player2->actionCount == 1) {
        game->currentPlayerIdx = 0;
        game->player2->actionCount = 0;
    }
}
}