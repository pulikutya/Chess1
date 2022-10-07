#include "main.h"
namespace stdio {
#include<stdio.h>
}

#include"LinkedList2.h"


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
	
}