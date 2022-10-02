#include "Board.h"


constexpr byte defaultBoardState[64] = {	
idWhiteRook,	idWhiteKnight,	idWhiteBishop,	idWhiteKing,	idWhiteQueen,	idWhiteBishop,	idWhiteKnight,	idWhiteRook,	
idWhitePawn,	idWhitePawn,	idWhitePawn,	idWhitePawn,	idWhitePawn,	idWhitePawn,	idWhitePawn,	idWhitePawn,	
idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,	
idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,	
idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,	
idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,		idEmpty,	
idBlackPawn,	idBlackPawn,	idBlackPawn,	idBlackPawn,	idBlackPawn,	idBlackPawn,	idBlackPawn,	idBlackPawn,	
idBlackRook,	idBlackKnight,	idBlackBishop,	idBlackKing,	idBlackQueen,	idBlackBishop,	idBlackKnight,	idBlackRook,	
};

constexpr byte emptyBoardState[64] = {
	idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty,idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty,idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty,idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty,idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty,idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty,idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty,idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty, idEmpty
};


Board::Board(bool defaultState) 
	: WhiteCastleLeftPossible(true), WhiteCastleRightPossible(true), BlackCastleLeftPossible(true), BlackCastleRightPossible(true)
{
	if (defaultState) {
		//CopyArray(squares, defaultBoardState)
		CopyArray(defaultBoardState, squares, 64);
	}
	else
	{
		CopyArray(defaultBoardState, squares, 64);
	}

}


char PieceIdToString(byte pieceId/*,byte colors[4]*/)
{
	switch (pieceId)
	{
		case idEmpty:		{ return ' '; }
		case idWhiteKing:	{ return 'K'; }
		case idBlackKing:	{ return 'k'; }
		case idWhiteKnight: { return 'N'; }
		case idBlackKnight: { return 'n'; }
		case idWhitePawn:	{ return 'P'; }
		case idBlackPawn:	{ return 'p'; }
		case idWhiteRook:	{ return 'R'; }
		case idBlackRook:	{ return 'r'; }
		case idWhiteBishop: { return 'B'; }
		case idBlackBishop: { return 'b'; }
		case idWhiteQueen:	{ return 'Q'; }
		case idBlackQueen:	{ return 'q'; }
		default: { throw - 3; }
	}
	//return string;
}
#define XfromI(i) ((i) % 8 + 1)
#define YfromI(i) ((i) / 8 + 1)
#define IfromXY(x, y) (((y)-1)*8+(x-1))


char* Board::string(bool large)
{

	char string[109] = 
"  abcdefgh\n        \n8 --------\n7 --------\n6 --------\n5 --------\n4 --------\n3 --------\n2 --------\n1 --------\0";
	//char places[64] = {24, 25, 26, 27, 28, 29, 30, 31, 35, 36, 37, 38, 39, 40, 41, 42, 46}
	byte c = 0;
	for (byte i = 22; c<64; i+= 3)
	{
		for (byte u = 0; u < 8; u++)
		{
			string[i] = 
				PieceIdToString(squares[c]);
			c++;
			i++;
		}
	}
		
	


	//we need to color it also
	return string;
}























#define abs(x) ((x) > 0? (x) : 0-(x))
#define sign(x) ((x) > 0? 1 : ((x) < 0? -1 : 0));
#define isPoitive(x) ((x) > 0)
#define neg(x) (0-(x))

bool NeutralKing_MoveLegal(sbyte dx, sbyte dy);
bool NeutralKnight_MoveLegal(sbyte dx,sbyte dy);


bool Board::IsMoveLegal(byte* m)
{
	sbyte start = m[0];
	sbyte end = m[1];
	sbyte extra = m[2];
	//redesign short processing
	
	

	if (!(isCoordInBoard(start) && isCoordInBoard(end))) { throw -1; }
	byte startPieceId = squares[start];
	byte endPieceId = squares[end];

	//if (isWhite(end) == isWhite(start)) { return false; }

	bool isStartWhite = isWhite(startPieceId);
	bool isEndWhite = isWhite(endPieceId);

	bool isEndEmpty = isEmpty(endPieceId);

	sbyte sx = XfromI(start), ex = XfromI(end);
	sbyte sy = YfromI(start), ey = YfromI(end);

	sbyte dx = ex-sx;
	sbyte dy = ey-sy;

	if (dx == 0 && dy == 0) { throw -2; }

	switch (startPieceId)
	{
		case idEmpty: { return false; }
		case idWhiteKing:
		{
			return (NeutralKing_MoveLegal(dx, dy) && (isEndEmpty || !isEndWhite));
		}
		case idBlackKing:
		{
			return (NeutralKing_MoveLegal(dx, dy) && (isEndEmpty || isEndWhite));
		}
		case idWhiteKnight:
		{
			return (NeutralKnight_MoveLegal(dx, dy) && (isEndEmpty || !isEndWhite));
		}
		case idBlackKnight:
		{
			return (NeutralKnight_MoveLegal(dx, dy) && (isEndEmpty || isEndWhite));
		}
		case idWhitePawn:
		{
			return (isEndEmpty && dx == 0 && (dy == 1 || (dy == 2 && sy == 2))) || (!isEndWhite && abs(dx) == 1 && sy == 1);
		}
		case idBlackPawn:
		{
			return (isEndEmpty && dx == 0 && (dy == -1 || (dy == -2 && sy == 6))) || (isEndWhite && abs(dx) == 1 && sy == -1);
		}
		case idWhiteRook:
		{
			return NeutralRook_MoveLegal(dx, dy, sx, sy, ex, ey) && (isEndEmpty || !isEndWhite);
		}
		case idBlackRook:
		{
			return NeutralRook_MoveLegal(dx, dy, sx, sy, ex, ey) && (isEndEmpty || isEndWhite);
		}
		case idWhiteBishop:
		{
			return NeutralBishop_MoveLegal(dx, dy, sx, sy, ex, ey) && (isEndEmpty || !isEndWhite);
		}
		case idBlackBishop:
		{
			return NeutralBishop_MoveLegal(dx, dy, sx, sy, ex, ey) && (isEndEmpty || isEndWhite);
		}
		case idWhiteQueen:
		{
			return NeutralQueen_MoveLegal(dx, dy, sx, sy, ex, ey) && (isEndEmpty || !isEndWhite);
		}
		case idBlackQueen:
		{
			return NeutralQueen_MoveLegal(dx, dy, sx, sy, ex, ey) && (isEndEmpty || isEndWhite);
		}
		default: { throw -3; }
	}
}





inline bool NeutralKing_MoveLegal(sbyte dx, sbyte dy)
{
	return abs(dx) + abs(dy) < 2;
}

inline bool NeutralKnight_MoveLegal(sbyte dx, sbyte dy)
{
	return abs(dx) + abs(dy) == 3;
}

bool Board::NeutralRook_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey)
{
	sbyte c = 0;
	bool cmpl = false;
	sbyte cp = 0;

	if (dx == 0)
	{
		if (dy > 0)
		{
			c = IfromXY(sx, sy + 1);
			cmpl = false;
			cp = 8;
		}
		else if (dy < 0)
		{
			c = IfromXY(sx, sy - 1);
			cmpl = true;
			cp = -8;
		}
		else { return false; }
	}
	else if (dy == 0)
	{
		if (dx > 0)
		{
			c = IfromXY(sx + 1, sy);
			cmpl = false;
			cp = 1;
		}
		else if (dx < 0)
		{
			c = IfromXY(sx - 1, sy);
			cmpl = true;
			cp = -1;
		}
		else { return false; }
	}
	else { return false; }

	bool pathfree = true;
	for (sbyte ce = IfromXY(ex, ey); (cmpl ? c > ce : c < ce) && pathfree; c += cp)
	{
		pathfree = isEmpty(squares[c]);
	}
	return pathfree;
}

bool Board::NeutralBishop_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey)
{
	bool pathfree = true;
	sbyte cp = 0;
	bool cmpl = false;
	sbyte c = 0;
	if (dx > 0)
	{
		
		if (dy == dx)
		{
			cmpl = false;
			cp = 9;
			c = IfromXY(dx + 1, dy + 1);
		}
		else if (dy == neg(dx))
		{
			cmpl = true;
			cp = -7;
			c = IfromXY(dx + 1, dy - 1);
		}
		else { return false; }
	}
	else if (dx < 0)
	{
		if (dy == dx)
		{
			cmpl = true;
			cp = -9;
			c = IfromXY(dx - 1, dy - 1);
		}
		else if (dy == neg(dx))
		{
			cmpl = false;
			cp = 7;
			c = IfromXY(dx - 1, dy + 1);
		}
		else { return false; }
	}
	else { return false; }

	for (sbyte ce = IfromXY(ex, ey); (cmpl ? c > ce : c < ce) && pathfree; c += cp)
	{
		pathfree = isEmpty(squares[c]);
	}
	return pathfree;
}

bool Board::NeutralQueen_MoveLegal(sbyte dx, sbyte dy, sbyte sx, sbyte sy, sbyte ex, byte ey)
{
	return NeutralBishop_MoveLegal(dx, dy, sx, sy, ex, ey) || NeutralRook_MoveLegal(dx, dy, sx, sy, ex, ey);
}