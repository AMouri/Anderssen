#include "board.h" 
#include "moves.h"

U64 wSinglePawnPush(){ return shiftN(pieces[WHITE] & pieces[PAWN]) & OPEN_BOARD; }

U64 wDoublePawnPush(){ return shiftN(wSinglePawnPush() & OPEN_BOARD) & getRank(4) & OPEN_BOARD; }

U64 bSinglePawnPush(){ return shiftS(pieces[BLACK] & pieces[PAWN]) & OPEN_BOARD; }

U64 bDoublePawnPush(){ return shiftS(bSinglePawnPush() & OPEN_BOARD) & getRank(5) & OPEN_BOARD; }

U64 wPawnToPushSingle(){ return shiftS(OPEN_BOARD) & pieces[WHITE] & pieces[PAWN]; }

U64 wPawnToPushDouble(){ return pieces[WHITE] & pieces[PAWN] & shiftS(shiftS(OPEN_BOARD & getRank(4)) & OPEN_BOARD); }

U64 bPawnToPushSingle(){ return shiftN(OPEN_BOARD) & pieces[BLACK] & pieces[PAWN]; }

U64 bPawnToPushDouble(){ return pieces[BLACK] & pieces[PAWN] & shiftN(shiftN(OPEN_BOARD & getRank(5)) & OPEN_BOARD); }

U64 wPawnAttacksNW(){ return shiftNW(pieces[WHITE] & pieces[PAWN]); }

U64 wPawnAttacksNE(){ return shiftNE(pieces[WHITE] & pieces[PAWN]); }

U64 bPawnAttacksSW(){ return shiftSW(pieces[BLACK] & pieces[PAWN]); }

U64 bPawnAttacksSE(){ return shiftSE(pieces[BLACK] & pieces[PAWN]); }

U64 knightNNE(){ return shiftN(shiftNE(pieces[KNIGHT])); }

U64 knightNEE(){ return shiftNE(shiftE(pieces[KNIGHT])); }

U64 knightSEE(){ return shiftSE(shiftE(pieces[KNIGHT])); }

U64 knightSSE(){ return shiftS(shiftSE(pieces[KNIGHT])); }

U64 knightSSW(){ return shiftS(shiftSW(pieces[KNIGHT])); }

U64 knightSWW(){ return shiftSW(shiftS(pieces[KNIGHT])); }

U64 knightNWW(){ return shiftNW(shiftW(pieces[KNIGHT])); }

U64 knightNNW(){ return shiftN(shiftNW(pieces[KNIGHT])); }
