#include "board.h"
#include <stdio.h>

enum piece_enum pieceColor(Piece_t p){ return p.c; }

enum piece_enum pieceType(Piece_t p){ return p.p; }

U64_t getPieceSet(Piece_t p){ return pieces[pieceColor(p)] & pieces[pieceType(p)]; }

U64 getRank(int pos){ return 0x00000000000000FF << (pos - 1)*8; }
U64 getFile(int pos){ return 0x0101010101010101 << (pos - 1); }

U64 shiftN(U64 b){ return b << 8; }
U64 shiftE(U64 b){ return (b << 1) & ~getFile(1); }
U64 shiftS(U64 b){ return b >> 8; }
U64 shiftW(U64 b){ return (b >> 1) & ~getFile(8); }
U64 shiftNE(U64 b){ return (b << 9) & ~getFile(1); }
U64 shiftSE(U64 b){ return (b >> 7) & ~getFile(1); }
U64 shiftSW(U64 b){ return (b >> 9) & ~getFile(8); }
U64 shiftNW(U64 b){ return (b << 7) & ~getFile(8); }

/*Board state is initialized to default starting position */
void init_board(){
    /* We will use a Little-endian Rank-File Mapping */
    pieces[WHITE] = 0x000000000000FFFF;
    pieces[BLACK] = 0xFFFF000000000000;
    pieces[PAWN] = 0x00FF00000000FF00;
    pieces[KNIGHT] = 0x4200000000000042;
    pieces[BISHOP] = 0x2400000000000024;
    pieces[ROOK] = 0x8100000000000081;
    pieces[QUEEN] = 0x0800000000000008;
    pieces[KING] = 0x1000000000000010;
}

void print_board(){
    printf("White pieces:\n");
    print_bits(pieces[WHITE]);
    printf("\nBlack pieces:\n");
    print_bits(pieces[BLACK]);
    printf("\nPawns:\n");
    print_bits(pieces[PAWN]);
    printf("\nKnights:\n");
    print_bits(pieces[KNIGHT]);
    printf("\nBishops:\n");
    print_bits(pieces[BISHOP]);
    printf("\nRooks:\n");
    print_bits(pieces[ROOK]);
    printf("\nQueens:\n");
    print_bits(pieces[QUEEN]);
    printf("\nKings:\n");
    print_bits(pieces[KING]);
}

void print_bits(U64_t b){
    int j = 63;
    int k;
    for(j; j >= 0; j = j - 8){
        for(k = j - 7; k <= j; k++){
            printf("%lld", (b >> k) & 1);
        }
        printf("\n");
    } 
}
