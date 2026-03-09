  #include <stdlib.h>
  #include <stdio.h>
  #include "Legality.h"
  #include "GameService.h"
  #include "BoardService.h"


  static void whitePawnEdge(ChessGame * game , Move move) {
    Board gameBoard;
    gameBoard = *(game->board);
    if(move.moveFrom%8 == 0) {
      if(gameBoard.boardPositions[move.moveTo].color == BLACK){
    if(move.moveTo - move.moveFrom != 9) {
       game->Status = "Pawn is on edge";
         return;
        }
         movePiece(game,move);
            } else {
         game->Status = "target piece is not black";
             return;
            }
         } else if(move.moveFrom%8 == 7) {
            if(gameBoard.boardPositions[move.moveTo].color == BLACK){
         if(move.moveTo-move.moveFrom != 7) {
               game->Status = "Pawn is on edge";
                   return;
                    }
                    movePiece(game,move);
             } else {
              game->Status = "target piece is not black";
               return;
                 }
             } 
  }

 static void blackPawnEdge(ChessGame * game , Move move){
    Board gameBoard;
    gameBoard = *(game->board);
    if(move.moveFrom%8 == 0) {
      if(gameBoard.boardPositions[move.moveTo].color == WHITE){
    if(move.moveTo - move.moveFrom != -9) {
       game->Status = "illegal Pawn Move";
         return;
        }
         movePiece(game,move);
            } else {
         game->Status = "target piece is not White";
             return;
            }
         } else if(move.moveFrom%8 == 7) {
            if(gameBoard.boardPositions[move.moveTo].color == WHITE){
         if(move.moveTo-move.moveFrom != -7) {
               game->Status = "illegal Pawn Move";
                   return;
                    }
                    movePiece(game,move);
             } else {
              game->Status = "target piece is not White";
               return;
                 }
             } 
  }

 static void whitePawnMovement(ChessGame * game , Move move) {
    Board gameBoard;
    gameBoard = *(game->board);
        if(move.moveFrom/8 == 1) {
                if(move.moveTo-move.moveFrom == 8) {
                if(gameBoard.boardPositions[move.moveTo].type != EMPTY){
                    game->Status = "Pawn can't go to occupied Positions";
                    return;
                }
                movePiece(game,move);
            } else if(move.moveTo-move.moveFrom == 16){
                if(gameBoard.boardPositions[move.moveFrom+8].type != EMPTY 
                 || gameBoard.boardPositions[move.moveTo].type != EMPTY){
                    game->Status = "Pawn can't go over Pieces";
                    return;
                } 
                movePiece(game , move);
            } else if (move.moveTo - move.moveFrom == 7 || move.moveTo - move.moveFrom == 9){
                     if(move.moveFrom%8 != 0 && move.moveFrom%8 != 7) {
                          if (gameBoard.boardPositions[move.moveTo].color == BLACK) {
                                movePiece(game,move);
                        } else {
                           game->Status = "target piece is not Black";
                                  return;
                                         }
                               } else whitePawnEdge(game , move);
        } else if(move.moveTo-move.moveFrom == 8){
            if(game->board->boardPositions[move.moveTo].type != EMPTY){
                game->Status = "Pawn can't go to occupied positions";
                return;
            }
            movePiece(game , move);
        } else if (move.moveTo - move.moveFrom == 7 || move.moveTo - move.moveFrom == 9){
        if(move.moveFrom%8 != 0 && move.moveFrom%8 != 7) {
        if (gameBoard.boardPositions[move.moveTo].color == BLACK) {
         movePiece(game,move);
       } else {
        game->Status = "target piece is not Black";
        return;
       }
    } else whitePawnEdge(game , move);
} else{
    game->Status = "illegal Pawn Movement";
    return;
}
        } else {
            game->Status = "illegal Pawn Movement";
            return;
        } 
  }

static void blackPawnMovement(ChessGame * game , Move move) {
    Board gameBoard;
    gameBoard = *(game->board);
            if(move.moveFrom/8 == 6) {
                if(move.moveTo-move.moveFrom == -8) {
                if(gameBoard.boardPositions[move.moveTo].type != EMPTY){
                    game->Status = "Pawn can't go to occupied positions";
                    return;
                }
                movePiece(game,move);
                } else if(move.moveTo-move.moveFrom == -16){
               if(gameBoard.boardPositions[move.moveFrom-8].type != EMPTY 
                 || gameBoard.boardPositions[move.moveTo].type != EMPTY){
                    game->Status = "Pawn can't go over Pieces";
                    return;
                }
                movePiece(game ,move);
            } else if (move.moveTo - move.moveFrom == -7 || move.moveTo - move.moveFrom == -9){
        if(move.moveFrom%8 != 0 && move.moveFrom%8 != 7) {
        if (gameBoard.boardPositions[move.moveTo].color == WHITE) {
         movePiece(game,move);
        } else {
        game->Status = "Target piece is not White";
        return;
       } 
       } else blackPawnEdge(game,move); 
        } else if(move.moveTo-move.moveFrom == -8){
        if(gameBoard.boardPositions[move.moveTo].type != EMPTY){
                 game->Status = "Pawn can't go occupied positions";
                 return;
                }
                movePiece(game,move);
        } else if (move.moveTo - move.moveFrom == -7 || move.moveTo - move.moveFrom == -9){
        if(move.moveFrom%8 != 0 && move.moveFrom%8 != 7) {
        if (gameBoard.boardPositions[move.moveTo].color == WHITE) {
         movePiece(game,move);
       } else {
        game->Status = "Target piece is not White";
        return;
    }
    } else blackPawnEdge(game ,move);
        } else {
            game->Status = "illegal Pawn Movement";
            return;
        }
    } else {
        game->Status = "illegal Pawn Movement";
        return;
    } 
} 




  void rookLegality(ChessGame * game , Move move) {
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
    Board gameBoard;
    gameBoard = *(game->board);
    if(gameBoard.boardPositions[move.moveFrom].type == ROOK) {
        if(move.moveTo == move.moveFrom){
            game->Status = "Rook is already on this Position";
            return;
        }
        if(move.moveFrom/8 != move.moveTo/8 && move.moveFrom%8 != move.moveTo%8){
            game->Status = "Rook can only move horizontally or vertically";
            return;
        }
        if(move.moveFrom/8 == move.moveTo/8) {
            if(move.moveTo > move.moveFrom){
                for(int i = move.moveFrom+1;i<move.moveTo;i++){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Rook can't go over pieces";
                        return;
                    }
                }
            } else{
                for(int i = move.moveFrom-1;i>move.moveTo;i--){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Rook can't go over pieces";
                        return;
                    }
                }
            }
        } else if(move.moveFrom%8 == move.moveTo%8){
            if(move.moveTo > move.moveFrom){
                for(int i=move.moveFrom+8;i<move.moveTo;i+=8){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Rook can't go over pieces";
                        return;
                    }
                }
            } else{
                for(int i=move.moveFrom-8;i>move.moveTo;i-=8){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Rook can't go over pieces";
                        return;
                    }
            }
        }   
        }
        movePiece(game,move);
        } else{
            game->Status = "piece is not a rook or no piece exists on that position";
            return;
        }
    }

    void bishopLegality(ChessGame *game , Move move) {
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
    Board gameBoard;
     int prevRow = move.moveFrom/8;
        int prevColumn = move.moveFrom%8;
        int newRow = move.moveTo/8;
        int newColumn = move.moveTo%8;
    gameBoard = *(game->board);
    if(gameBoard.boardPositions[move.moveFrom].type == BISHOP){
        if(move.moveFrom == move.moveTo){
            game->Status = "Bishop is already on this Position";
            return;
        }
        if(abs(prevRow-newRow) != abs(prevColumn-newColumn)){
            game->Status = "illegal Bishop move";
            return;
        }
        if(move.moveFrom>move.moveTo){
            if((move.moveFrom-move.moveTo)%7 == 0){
            for(int i = move.moveFrom-7;i>move.moveTo;i-=7){
                if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                    game->Status = "Bishop can't go over Pieces";
                    return;
                }
            }
        } else if((move.moveFrom-move.moveTo)%9 == 0){
            for(int j =move.moveFrom-9;j>move.moveTo; j-=9){
                if(gameBoard.boardPositions[j].color != NO_COLOR && gameBoard.boardPositions[j].type != EMPTY){
                    game->Status = "Bishop can't go over Pieces";
                    return;
                }
            }
        }
        } else {
            if((move.moveTo-move.moveFrom)%7 == 0){
              for(int i = move.moveFrom+7;i<move.moveTo;i+=7){
                if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                    game->Status = "Bishop can't go over Pieces";
                    return;
                }
            }
        } else if((move.moveTo-move.moveFrom)%9 == 0){
            for(int j =move.moveFrom+9;j<move.moveTo; j+=9){
                if(gameBoard.boardPositions[j].color != NO_COLOR && gameBoard.boardPositions[j].type != EMPTY){
                    game->Status = "Bishop can't go over Pieces";
                    return;
                }
            }
        }
        }
        movePiece(game,move);

    } else{
        game->Status = "piece is not a Bishop or no piece exists on that position";
        return;
    }
    }

    void queenLegality(ChessGame*game , Move move){
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
    Board gameBoard;
    gameBoard = *(game->board);
    int prevRow = move.moveFrom/8;
        int prevColumn = move.moveFrom%8;
        int newRow = move.moveTo/8;
        int newColumn = move.moveTo%8;
    if(gameBoard.boardPositions[move.moveFrom].type == QUEEN){
        if(move.moveFrom == move.moveTo){
            game->Status = "Queen is already on this position";
            return;
        }
        if(move.moveFrom/8 == move.moveTo/8 || move.moveFrom%8 == move.moveTo%8){
        if(move.moveFrom/8 == move.moveTo/8) {
            if(move.moveTo > move.moveFrom){
                for(int i = move.moveFrom+1;i<move.moveTo;i++){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Queen can't go over pieces";
                        return;
                    }
                }
            } else{
                for(int i = move.moveFrom-1;i>move.moveTo;i--){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Queen can't go over pieces";
                        return;
                    }
                }
            }
        } else if(move.moveFrom%8 == move.moveTo%8){
            if(move.moveTo > move.moveFrom){
                for(int i=move.moveFrom+8;i<move.moveTo;i+=8){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Queen can't go over pieces";
                        return;
                    }
                }
            } else{
                for(int i=move.moveFrom-8;i>move.moveTo;i-=8){
                    if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                        game->Status = "Queen can't go over pieces";
                        return;
                    }
            }
        }   
        }
        movePiece(game, move);
    } 
        else if(abs(prevRow-newRow) == abs(prevColumn-newColumn)) {
            
        if(move.moveFrom>move.moveTo){
            if((move.moveFrom-move.moveTo)%7 == 0){
            for(int i = move.moveFrom-7;i>move.moveTo;i-=7){
                if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                    game->Status = "Queen can't go over Pieces";
                    return;
                }
            }
        } else if((move.moveFrom-move.moveTo)%9 == 0){
            for(int j =move.moveFrom-9;j>move.moveTo; j-=9){
                if(gameBoard.boardPositions[j].color != NO_COLOR && gameBoard.boardPositions[j].type != EMPTY){
                    game->Status = "Queen can't go over Pieces";
                    return;
                }
            }
        }
        } else {
            if((move.moveTo-move.moveFrom)%7 == 0){
              for(int i = move.moveFrom+7;i<move.moveTo;i+=7){
                if(gameBoard.boardPositions[i].color != NO_COLOR && gameBoard.boardPositions[i].type != EMPTY){
                    game->Status = "Queen can't go over Pieces";
                    return;
                }
            }
        } else if((move.moveTo-move.moveFrom)%9 == 0){
            for(int j =move.moveFrom+9;j<move.moveTo; j+=9){
                if(gameBoard.boardPositions[j].color != NO_COLOR && gameBoard.boardPositions[j].type != EMPTY){
                    game->Status = "Queen can't go over Pieces";
                    return;
                }
            }
        }
    }
    movePiece(game , move);
        } else{
            game->Status = "illegal Queen Move";
            return;
        }
    } else{
        game->Status = "piece is not a Queen or no piece exists on that position";
        return;
    }
    }

    void knightLegality(ChessGame*game , Move move){
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
    Board gameBoard;
    gameBoard = *(game->board);
    if(gameBoard.boardPositions[move.moveFrom].type == KNIGHT) {
        if(move.moveFrom == move.moveTo) {
            game->Status = "knight is already on this position";
            return;
        }
        if((abs(move.moveFrom%8 - move.moveTo%8)!= 2 && abs(move.moveFrom/8 - move.moveTo/8) != 1) && 
        (abs(move.moveFrom%8 - move.moveTo%8) != 1 && abs(move.moveFrom/8 - move.moveTo/8) != 2)) {
            game->Status = "invalid knight move";
            return;
        }
        movePiece(game,move);
        } else {
            game->Status = "piece is not a knight or there is no piece";
            return;
        }
    }


    
    void kingLegality(ChessGame*game , Move move){
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
    Board gameBoard;
    gameBoard = *(game->board);
    if(game->board->boardPositions[move.moveFrom].type == KING) {
        if(move.moveFrom == move.moveTo) {
            game->Status = "King is already on this position";
            return;
        }
        if(abs(move.moveFrom/8 - move.moveTo/8)>1 || abs(move.moveFrom%8-move.moveTo%8)>1){
        game->Status = "illegal King move";
        return;
    }
    movePiece(game , move);
    } else{
        game->Status = "piece is not a king or no piece on this position";
        return;
    }
}

void pawnLegality(ChessGame*game , Move move) {
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
    Board gameBoard;
    gameBoard = *(game->board);
    if(gameBoard.boardPositions[move.moveFrom].type == PAWN) {
        if(move.moveTo == move.moveFrom) {
            game->Status = "Pawn is already on this position";
            return;
        }
        if(gameBoard.boardPositions[move.moveFrom].color == WHITE) whitePawnMovement(game , move);
        else if(game->board->boardPositions[move.moveFrom].color == BLACK) blackPawnMovement(game,move);  
} else {
    game->Status = "Piece is not a Pawn";
    return;
}
}