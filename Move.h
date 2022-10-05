#include "main.h"
#pragma once
#include"Piece.h"
class Move
{	
public:
	ushort data;

	inline Move(byte start, byte end, byte extra);
	inline Move(ushort data);
	Move(byte sx, byte sy, byte ex, byte ey, byte extra);
	inline Move(char text[5]);

	inline byte start();
	inline byte end();
	inline byte extra();
	
	inline sbyte sx();
	inline sbyte sy();
	inline sbyte ex();
	inline sbyte ey();
	inline sbyte dx();
	inline sbyte dy();

	inline byte extra_promotion();
	inline bool extra_castling();
	inline bool extra_el_passant();

	inline char* ToString();


	bool MoveLegal1(Piece piece);
};

