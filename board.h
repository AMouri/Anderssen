#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

/*Denote bitboards by the shorthand U64 (unsigned 64-bit)*/
typedef unsigned long long U64_t;

/*Array of 8 bitboards. Two for each color, and six for color independent pieces */
U64_t pieces[8];

enum piece_enum {WHITE, BLACK, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING};

typedef struct{
    enum piece_enum c;
    enum piece_enum p;
}Piece_t;

enum piece_enum pieceColor(Piece_t p);

enum piece_enum pieceType(Piece_t p);

U64_t getPieceSet(Piece_t p);

/* Get rank/file. Same ordering as chessboard. Note 1-8 maps to A-H */
U64 getRank(int pos);
U64 getFile(int pos);

/* Shift bitboard by 1 in that direction*/
U64 shiftN(U64 b);
U64 shiftE(U64 b);
U64 shiftS(U64 b);
U64 shiftW(U64 b);
U64 shiftNE(U64 b);
U64 shiftSE(U64 b);
U64 shiftSW(U64 b);
U64 shiftNW(U64 b);

/* Initializes the board */
void init_board();

/* Prints the bitboards in a human readable format for debugging purposes*/
void print_board();

/* Prints a given bitboard */
void print_bits(U64_t b);

#define EMPTY_SET 0
#define UNIVERSAL_SET 0xFFFFFFFFFFFFFFFF
#define OCCUPIED (WHITE & BLACK)
#define OPEN_BOARD ~OCCUPIED

#endif
