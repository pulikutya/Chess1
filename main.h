#pragma once
typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long int ulong;

#define CopyArray(from, to, size) for(ulong i = 0; i < (size); i++) {(to)[i] = (from)[i];}
