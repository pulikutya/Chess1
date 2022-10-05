#include "main.h"
#pragma once
#include"Block.h"
#include"Move.h"
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
	Block<Piece> data;
	static const size_t data_length = 64;

	byte el_passant_info = 0;
	byte castling_info = 0;

	inline bool Can_WhiteCastleKingSide();
	inline bool Can_WhiteCastleQueenSide();
	inline bool Can_BlackCastleKingSide();
	inline bool Can_BlackCastleQueenSide();


	Board(Block<Piece> data);
	Board(bool defaultState = true);

	inline Piece TargetPiece(Move Move);
	inline Piece StartPiece(Move Move);

	void Do(Move Move);
	void Undo(Move Move, Piece Capture);

	bool MoveLegal(Move Move, bool IncludeCheck);


	Block<Move> AllLegalMovesForAPiece(byte coords);
	Block<Move> AllLegalMoves();

	char* ToText(byte type);
};