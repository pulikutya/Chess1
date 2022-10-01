#include "main.h"
#pragma once
#include"Piece.h"



#define isCoordInBoard(coord) (coord < 64)
class Board
{
public:
	byte squares[64];
	static const size_t squares_size = 64;

	Board(bool defaultState = true);

	bool WhiteCastleLeftPossible;
	bool WhiteCastleRightPossible;
	bool BlackCastleLeftPossible;
	bool BlackCastleRightPossible;

	bool IsMoveLegal(short move);

	char* string(bool large);

private:
	bool NeutralRook_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey);
	bool NeutralBishop_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey);
	bool NeutralQueen_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey);
	
};

