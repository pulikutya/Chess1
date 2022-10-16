#include"main.h"
#pragma once


#define isWhite(pieceId) (pieceId % 2 == 0)
#define isBlack(pieceId) (pieceId % 2 == 1)
#define isEmpty(pieceId) (pieceId == idEmpty)

#define isPawn(pieceId) ((pieceId >> 1) % (idNeutralPawn & 0b01111) == 0)


class Piece
{
public:
	static constexpr byte idEmpty		= 0b0000;

	static constexpr byte idWhitePawn	= 0b0010;
	static constexpr byte idWhiteKnight	= 0b0100;
	static constexpr byte idWhiteBishop	= 0b0110;
	static constexpr byte idWhiteRook	= 0b1000;
	static constexpr byte idWhiteQueen	= 0b1010;
	static constexpr byte idWhiteKing	= 0b1100;

	static constexpr byte idBlackPawn	= 0b0011;
	static constexpr byte idBlackKnight	= 0b0101;
	static constexpr byte idBlackBishop	= 0b0111;
	static constexpr byte idBlackRook	= 0b1001;
	static constexpr byte idBlackQueen	= 0b1011;
	static constexpr byte idBlackKing	= 0b1101;

	Piece(byte id);

	byte id;
	byte Color(); //empty, white, black, neutral
	inline bool Empty();
	inline bool White();
	inline bool Black();

	inline bool ColorEqual(Piece& other);
	inline bool TypeEqual(Piece& other);

};