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

	inline void start(byte v);
	inline void end(byte v);
	inline void extra(byte v);

	inline void sx(sbyte v);
	inline void sy(sbyte v);
	inline void ex(sbyte v);
	inline void ey(sbyte v);
	inline void dx(sbyte v);
	inline void dy(sbyte v);

	inline void extra_promotion(byte v);
	inline void extra_castling(bool v);
	inline void extra_el_passant(bool v);


	bool MoveLegal1(Piece piece);
};

