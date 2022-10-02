#include "Move.h"
#include "smath.h"

Move::Move(byte start, byte end, byte extra)
{
}

Move::Move(ushort data)
{
}

Move::Move(byte sx, byte sy, byte ex, byte ey)
{

}

Move::Move(char text[5])
{

}

inline byte Move::start()
{
    return byte();
}

inline byte Move::end()
{
    return byte();
}

inline byte Move::extra()
{
    return byte();
}

inline sbyte Move::sx()
{
    return this->start() % 8;
}

inline sbyte Move::sy()
{
    return this->start() / 8;
}

inline sbyte Move::ex()
{
    return this->end() % 8;
}

inline sbyte Move::ey()
{
    return this->end() / 8;
}

inline sbyte Move::dx()
{
    return this->ex() - this->sx();
}

inline sbyte Move::dy()
{
    return this->ey() - this->sy();
}

inline char* Move::ToString()
{
    return nullptr;
}

bool Move::NeutralLegal(byte pieceId)
{
    switch (pieceId)
    {
        case idEmpty: { return false; }
        case idNeutralKing: {
            abs(this->dx()) + abs(this->dy()) < 2;
        }
        
    }
}
