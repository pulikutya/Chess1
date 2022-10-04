#include "main.h"
#pragma once
#include"Piece.h"



#define isCoordInBoard(coord) (coord < 64)
/*
class Board
{
public:
	byte* squares;
	static const size_t squares_size = 64;

	Board(bool defaultState = true);

	bool WhiteCastleLeftPossible;
	bool WhiteCastleRightPossible;
	bool BlackCastleLeftPossible;
	bool BlackCastleRightPossible;

	bool IsMoveLegal(byte* m);

	char* string(bool large = false);


	void DoMoveForced(byte* move);


	char* MoveToText(byte* move);
	byte* TextToMove(char* text);

private:
	bool NeutralRook_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey);
	bool NeutralBishop_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey);
	bool NeutralQueen_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey);
	
};

*/

class Board
{
	byte* squares;
	static const size_t squares_length = 64;

	Board(byte* squares);
	Board(bool defaultState = true);
	Board(Board& Board);

};