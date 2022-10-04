#include "main.h"
namespace stdio {
#include<stdio.h>
}


void PrintNullString(char* string)
{
	try
	{
		while (*string != '\0')
		{
			stdio::printf("%c", *(string++));
		}
	}
	catch (...)
	{
		throw -1;
	}
	
}
int main()
{
	ushort t = 0b1001100001100001;
	byte* p = (byte*)(&t);

	byte a = 0;
	byte b = 0;
	byte c = 0;

	a = (p[0] << 2);
	a = a >> 2;

	b = p[0] >> 6;
	b = b | (p[1] << 2);
	b = b << 2;
	b = b >> 2;

	c = p[1] >> 4;

	return 0;
}