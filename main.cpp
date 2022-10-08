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
template<typename T>
void printlinkedlist(LinkedList2<T>* l)
{
	l->iter_reset();
	while (l->iter_next()) { stdio::printf("%v", l->iter_data()); }
}

int main()
{
	LinkedList2<int>* t = new LinkedList2<int>();
	t->AddElement(69);
	t->AddElement(420);
	t->AddElement(578);
	printlinkedlist(t);
	t->PopElement(1);
	printlinkedlist(t);
	t->InsertElement(0, 0);
	printlinkedlist(t);

}