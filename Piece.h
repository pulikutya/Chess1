#include"main.h"
#pragma once
constexpr byte idEmpty		= 0b0000;
//constexpr byte idEmpty2		= 0b0001;

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

#define isWhite(piece) (piece % 2)
#define isEmpty(piece) (piece == idEmpty)