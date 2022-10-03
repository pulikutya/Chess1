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
	byte a = true;
	int b = a;
	stdio::printf("%p", a);

	return 0;
}