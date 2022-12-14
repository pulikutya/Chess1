#include "Move.h"
#include "smath.h"

Move::Move(byte start, byte end, byte extra)
    :data(0)
{
    byte* p = (byte*)(&data);
    p[0] = (end << 4) | start;
    p[1] = (extra << 4) | (end >> 2);
}

Move::Move(ushort data)
    :data(data)
{
}

Move::Move(byte sx, byte sy, byte ex, byte ey, byte extra)
    : Move(sy*8+sx, ex*8+ey, extra)
{

}

Move::Move(char text[5])
    :data(0)
{

}

inline byte Move::start()
{
    byte r = ((byte*)(&data))[0] << 2;
    r >>= 2;
}

inline byte Move::end()
{
    byte r = ((byte*)(&data))[0] >> 6;
    r |= ((byte*)(&data))[1] << 2;
    r <<= 2;
    r >>= 2;
}

inline byte Move::extra()
{
    return ((byte*)(&data))[1] >> 4;
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

inline byte Move::extra_promotion()
{
    return byte();
}

inline bool Move::extra_castling()
{
    return false;
}

inline bool Move::extra_el_passant()
{
    return false;
}

inline char* Move::ToString()
{
    return nullptr;
}

inline void Move::start(byte v)
{
    *this = Move(v, end(), extra());
}

inline void Move::end(byte v)
{
    *this = Move(start(), v, extra());
}

inline void Move::extra(byte v)
{
    *this = Move(start(), end(), v);
}

inline void Move::sx(sbyte v)
{
    //start(sy() * 8 + v;
}

inline void Move::sy(sbyte v)
{
}

inline void Move::ex(sbyte v)
{
}

inline void Move::ey(sbyte v)
{
}

inline void Move::dx(sbyte v)
{
}

inline void Move::dy(sbyte v)
{
}

inline void Move::extra_promotion(byte v)
{
}

inline void Move::extra_castling(bool v)
{
}

inline void Move::extra_el_passant(bool v)
{
}
