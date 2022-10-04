#include"main.h"
#pragma once


#define isWhite(pieceId) (pieceId % 2 == 0)
#define isBlack(pieceId) (pieceId % 2 == 1)
#define isEmpty(pieceId) (pieceId == idEmpty)

#define isPawn(pieceId) ((pieceId >> 1) % (idNeutralPawn & 0b01111) == 0)


class Piece
{
public:


	#define idEmpty  0b0000;

	#define idPawn		0b001;
	#define idKnight	0b010;
	#define idBishop	0b011;
	#define idRook		0b100;
	#define idQueen		0b101;
	#define idKing		0b110;

	#define idWhitePawn			0b0010;
	#define idWhiteKnight		0b0100;
	#define idWhiteBishop		0b0110;
	#define idWhiteRook			0b1000;
	#define idWhiteQueen		0b1010;
	#define idWhiteKing			0b1100;

	#define idBlackPawn			0b0011;
	#define idBlackKnight		0b0101;
	#define idBlackBishop		0b0111;
	#define idBlackRook			0b1001;
	#define idBlackQueen		0b1011;
	#define idBlackKing			0b1101;

	Piece(byte id);

	byte id;
	byte Color(); //empty, white, black, neutral
	inline bool Empty();
	inline bool White();
	inline bool Black();

	inline bool ColorEqual(Piece& other);
	inline bool TypeEqual(Piece& other);

};