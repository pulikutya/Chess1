#include "main.h"
#pragma once
#include"Piece.h"
class Move
{	
public:
	ushort data;

	inline Move(byte start, byte end, byte extra);
	inline Move(ushort data);
	Move(byte sx, byte sy, byte ex, byte ey);
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

	inline char* ToString();


	bool NeutralLegal(byte pieceId);
};

