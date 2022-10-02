#include"main.h"
#pragma once
constexpr byte idEmpty			= 0b0000;

constexpr byte idNeutralPawn	= 0b10001;
constexpr byte idNeutralKnight	= 0b10010;
constexpr byte idNeutralBishop	= 0b100011;
constexpr byte idNeutralRook	= 0b10100;
constexpr byte idNeutralQueen	= 0b10101;
constexpr byte idNeutralKing	= 0b100110;

constexpr byte idWhitePawn		= 0b0010;
constexpr byte idWhiteKnight	= 0b0100;
constexpr byte idWhiteBishop	= 0b0110;
constexpr byte idWhiteRook		= 0b1000;
constexpr byte idWhiteQueen		= 0b1010;
constexpr byte idWhiteKing		= 0b1100;

constexpr byte idBlackPawn		= 0b0011;
constexpr byte idBlackKnight	= 0b0101;
constexpr byte idBlackBishop	= 0b0111;
constexpr byte idBlackRook		= 0b1001;
constexpr byte idBlackQueen		= 0b1011;
constexpr byte idBlackKing		= 0b1101;

#define isWhite(pieceId) (pieceId % 2 == 0)
#define isBlack(pieceId) (pieceId % 2 == 1)
#define isEmpty(pieceId) (pieceId == idEmpty)

#define isPawn(pieceId) ((pieceId >> 1) % (idNeutralPawn & 0b01111) == 0)