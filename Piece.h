#include"main.h"
#pragma once


#define isWhite(pieceId) (pieceId % 2 == 0)
#define isBlack(pieceId) (pieceId % 2 == 1)
#define isEmpty(pieceId) (pieceId == idEmpty)

#define isPawn(pieceId) ((pieceId >> 1) % (idNeutralPawn & 0b01111) == 0)


class Piece
{
public:
	static const byte idEmpty		= 0b0000;

	static const byte idWhitePawn	= 0b0010;
	static const byte idWhiteKnight	= 0b0100;
	static const byte idWhiteBishop	= 0b0110;
	static const byte idWhiteRook	= 0b1000;
	static const byte idWhiteQueen	= 0b1010;
	static const byte idWhiteKing	= 0b1100;

	static const byte idBlackPawn	= 0b0011;
	static const byte idBlackKnight	= 0b0101;
	static const byte idBlackBishop	= 0b0111;
	static const byte idBlackRook	= 0b1001;
	static const byte idBlackQueen	= 0b1011;
	static const byte idBlackKing	= 0b1101;

	Piece(byte id);

	byte id;
	byte Color(); //empty, white, black, neutral
	inline bool Empty();
	inline bool White();
	inline bool Black();

	inline bool ColorEqual(Piece& other);
	inline bool TypeEqual(Piece& other);

};