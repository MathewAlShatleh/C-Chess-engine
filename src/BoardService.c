#include <stdlib.h>
#include <stdio.h>
#include "BoardService.h"
#include "GameService.h"

void startingBoard(Board* board) {
 for (int i = 8; i<16;i++) {
    board->boardPositions[i].type = PAWN;  
 }
  for(int i = 0; i<=15;i++) {
board->boardPositions[i].color = WHITE;
 }
 board->boardPositions[0].type = ROOK;
 board->boardPositions[1].type = KNIGHT;
 board->boardPositions[2].type = BISHOP;
 board->boardPositions[3].type = QUEEN;
 board->boardPositions[4].type = KING;
 board->boardPositions[5].type = BISHOP;
 board->boardPositions[6].type = KNIGHT;
 board->boardPositions[7].type = ROOK;
 for(int i=55; i>=48; i--){
    board->boardPositions[i].type = PAWN;
 }
 for(int i = 63; i>=48; i--) {
board->boardPositions[i].color = BLACK;
 }
  board->boardPositions[63].type = ROOK;
 board->boardPositions[62].type = KNIGHT;
 board->boardPositions[61].type = BISHOP;
  board->boardPositions[60].type = KING;
 board->boardPositions[59].type = QUEEN;
 board->boardPositions[58].type = BISHOP;
 board->boardPositions[57].type = KNIGHT;
 board->boardPositions[56].type = ROOK;
 for(int i = 16; i<=47;i++) {
    board->boardPositions[i].type = EMPTY;
    board->boardPositions[i].color = NO_COLOR;
 }
}

Piece* removePiece(int postion , ChessGame* game) {
    char* status = checkGameStatus(game);
    if(status != NULL) {
        printf("%s\n" , status);
        return NULL;
    }
    if(postion<0 || postion>63) {
        game->Status = "no such Position exists";
        return NULL;
    }
    if(game->removedPiecesCounter >30){
        game->Status = "illegal count of removed Chess Pieces reached";
        return NULL;
    }
    int countSaver = game->removedPiecesCounter;
    if(game->board->boardPositions[postion].color != NO_COLOR && game->board->boardPositions[postion].type != EMPTY) {
    game->removedPieces[countSaver].color = game->board->boardPositions[postion].color;
    game->removedPieces[countSaver].type = game->board->boardPositions[postion].type;
    game->board->boardPositions[postion].type = EMPTY;
    game->board->boardPositions[postion].color = NO_COLOR;
    game->removedPiecesCounter++;
    } else {
        game->Status = "no Piece exists on this Position";
        return NULL;
    }
    return &(game->removedPieces[countSaver]);
}

void movePiece(ChessGame * game , Move move) {
    char* status = checkGameStatus(game);
    if(status != NULL) {
        printf("%s\n" , status);
        return;
    }
    if(move.moveFrom>=64 || move.moveFrom < 0) {
        game->Status = "no such Piece exists in that position , unknown locaton";
        return;
    }
    if(move.moveTo>=64 || move.moveTo< 0) {
        game->Status = "out of bound moves";
        return;
    }
if(game->board->boardPositions[move.moveFrom].color != NO_COLOR && game->board->boardPositions[move.moveFrom].type != EMPTY) {
    if(game->board->boardPositions[move.moveTo].color == NO_COLOR && game->board->boardPositions[move.moveTo].type == EMPTY) {
game->board->boardPositions[move.moveTo].color = game->board->boardPositions[move.moveFrom].color;
game->board->boardPositions[move.moveTo].type = game->board->boardPositions[move.moveFrom].type;
game->board->boardPositions[move.moveFrom].type = EMPTY;
game->board->boardPositions[move.moveFrom].color = NO_COLOR;
} else if(game->board->boardPositions[move.moveTo].color != NO_COLOR && game->board->boardPositions[move.moveTo].type != EMPTY) {
    if(game->board->boardPositions[move.moveFrom].color == game->board->boardPositions[move.moveTo].color){
        game->Status = "can't move piece to that position";
        return;
    } else{
          if(removePiece(move.moveTo , game) !=NULL ) {
game->board->boardPositions[move.moveTo].color = game->board->boardPositions[move.moveFrom].color;
game->board->boardPositions[move.moveTo].type = game->board->boardPositions[move.moveFrom].type;
game->board->boardPositions[move.moveFrom].type = EMPTY;
game->board->boardPositions[move.moveFrom].color = NO_COLOR;
    }
}
}
} else{
    game->Status = "no Piece exists on that position";
    return;
}
}