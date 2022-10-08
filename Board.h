#include "main.h"
#pragma once
#include"Block.h"
#include"Move.h"
#include"Piece.h"



#define isCoordInBoard(coord) (coord < 64)

class Board
{
public:
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