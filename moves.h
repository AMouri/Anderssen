#ifndef MOVES_H_INCLUDED
#define MOVES_H_INCLUDED

/* Functions to return targets of pawn pushes */
U64 wSinglePawnPush();
U64 wDoublePawnPush();
U64 bSinglePawnPush();
U64 bDoublePawnPush();

/* Functions to return pawns able to push */
U64 wPawnsToPushSingle();
U64 wPawnsToPushDouble();
U64 bPawnsToPushSingle();
U64 bPawnsToPushDouble();

/* Generate pawn attack squares*/
U64 wPawnAttacksNW();
U64 wPawnAttacksNE();
U64 bPawnAttacksSW();
U64 bPawnAttacksSE();

/* Generate knight attack squares */
U64 knightNNE();
U64 knightNEE();
U64 knightSEE();
U64 knightSSE();
U64 knightSSW();
U64 knightSWW();
U64 knightNWW();
U64 knightNNW();

#endif
