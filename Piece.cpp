#include "Piece.h"

Piece::Piece(byte id)
    :id(id)
{
}

byte Piece::Color()
{
    return this->White();
}

inline bool Piece::Empty()
{
    return this->id == 0 || this->id == 1;
}

inline bool Piece::White()
{
    return (this->id % 2);
}

inline bool Piece::Black()
{
    return !(this->id % 2);
}

inline bool Piece::ColorEqual(Piece& other)
{
    return ((other.Color() == this->Color() && !this->Empty() && !other.Empty()));
}

inline bool Piece::TypeEqual(Piece& other)
{
    return !this->Empty() && !other.Empty() && ((this->id >> 1) == (other.id >> 1));
}

