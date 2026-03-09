#ifndef ENTITIES_H
#define ENTITIES_H


typedef enum PieceColor {
    WHITE,
    BLACK,
    NO_COLOR,
}PieceColor;

typedef enum PieceType{
    KING,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN,
    EMPTY,
}PieceType;

typedef struct Piece{
PieceType type;
PieceColor color;
}Piece;

typedef struct Player {
char playerName[13];
int actionCount;
}Player;

typedef struct Board {
Piece boardPositions[64];
}Board;

typedef struct  Move
{
    int moveFrom;
    int moveTo;
}Move;

typedef struct ChessGame  {
Player *player1;
Player *player2;
char log[256];
int currentPlayerIdx;
Board *board;
Piece removedPieces[31];
int removedPiecesCounter;
char* Status;
}ChessGame; 

#endif