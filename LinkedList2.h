#include"main.h"
#pragma once
#include"LinkedList2Element.h"
#include"Block.h"
template<typename T>
class LinkedList2
{
public:
	LinkedList2Element<T>* First;
	LinkedList2Element<T>* Last;

	LinkedList2Element<T>* ElementAt(ulong index);
	T DataAt(ulong index);
	
	Block<T> Block();

	LinkedList2Element();
	LinkedList2Element(Block<T> Block);


	void AddElement(T Element);
	void AddBlock(Block<T> Block);

	void InsertElement(T Element);
	void InsertBlock(Block<T> Block);

	void RemoveElement(unsigned long long int index);
	void RemoveBlock(unsigned long long int index, size_t size);
};

