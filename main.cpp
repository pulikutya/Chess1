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
	byte a = 0;
	sbyte b = -69;
	a = b + 30;
	b = a / 8;
	int a2 = (int)a;
	int b2 = (int)b;

	return 0;
}