#include "Piece.h"

Piece::Piece(byte id)
    :id(id)
{
}

byte Piece::Color()
{
    return Empty()? 0: (Neutral? 1 : (White() ? 2 : 3));
}

inline bool Piece::Empty()
{
    return id == 0 || id == 1;
}

inline bool Piece::Neutral()
{
    return id > 16;
}

inline bool Piece::White()
{
    return (id % 2);
}

inline bool Piece::Black()
{
    return !(id % 2);
}

inline bool Piece::ColorEqual(Piece& other)
{
    return other.Color() == this->Color();
}

inline bool Piece::TypeEqual(Piece& other)
{
    return false;
}

