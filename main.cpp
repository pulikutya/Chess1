#include "main.h"
namespace stdio {
#include<stdio.h>
}

#include"LinkedList2.h"
#include"linq.h"

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
template<typename T>
void printlinkedlist(LinkedList2<T>* l)
{
	stdio::printf("LinkedList2<> {");
	l->iter_reset();
	while (l->iter_next()) { stdio::printf(",%v", l->iter_data()); }
	stdio::printf("}");
}
template<typename T>
void printblock(Block<T>* b)
{
	stdio::printf("Block<> {");
	b->iter_reset();
	while (b->iter_next()) 
	{ 
		stdio::printf(",%v", *(b->iter));
	}
	stdio::printf("}");
}

int main()
{
	LinkedList2<int>* t = new LinkedList2<int>();
	int ba[5] = { 3, 5, 7, 0, 1 };
	Block<int>* b = new Block<int>(ba, 5);
	printblock(b);
	t->AddBlock(*b);
	foreach(int, s, *b)
	{
		stdio::printf(",%u", s);
	}
	return 0;
}