#include <stdlib.h>
#include "Player.h"

Player * initializePlayers() {
    Player* player = malloc(sizeof *player);
    if(player != NULL) {
        player->actionCount = 0;
        player->playerName[0] = '\0';
        return player;
    }
return NULL;
}