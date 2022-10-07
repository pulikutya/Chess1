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

	LinkedList2Element<T>* iter;
	bool iter_next();
	bool iter_prev();
	void iter_reset();
	inline T* iter_data();

	Block<T> ToBlock();

	LinkedList2();
	LinkedList2(Block<T> Block);
	LinkedList2(LinkedList2Element<T>* First, LinkedList2Element<T>* Last);

	LinkedList2<T> Copy();

	LinkedList2Element<T>* ElementAt(ulong index);
	inline T DataAt(ulong index);

	void AddElement(T Element);
	void AddBlock(Block<T> Block);

	void InsertElement(T Element, ulong index);
	void InsertBlock(Block<T> Block, ulong index);

	size_t Count();

	T PopElement(unsigned long long int index);
	Block<T> PopBlock(unsigned long long int index, size_t size);
};

template<typename T>
inline bool LinkedList2<T>::iter_next()
{
	if (this->iter == this->Last)
	{
		return false;
	}
	else
	{
		this->iter = this->iter->Next;
		return this->iter != this->Last;
	}
}

template<typename T>
inline bool LinkedList2<T>::iter_prev()
{
	if (this->iter == this->First)
	{
		return false;
	}
	else
	{
		this->iter = this->iter->Previous;
		return this->iter != this->First;
	}
}

template<typename T>
inline void LinkedList2<T>::iter_reset()
{
	this->iter = First;
}

template<typename T>
inline T* LinkedList2<T>::iter_data()
{
	return this->iter->data;
}

template<typename T>
inline Block<T> LinkedList2<T>::ToBlock()
{
	return Block<T>();
}

template<typename T>
inline LinkedList2<T>::LinkedList2()
	:First(new LinkedList2Element<T>(nullptr, nullptr, nullptr)), Last(new LinkedList2Element<T>(nullptr, nullptr, nullptr))
{
	this->First->Next = Last;
	this->Last->Previous = First;
}

template<typename T>
inline LinkedList2<T>::LinkedList2(Block<T> Block) : LinkedList2<T>()
{
	this->AddBlock(Block);
}

template<typename T>
inline LinkedList2<T>::LinkedList2(LinkedList2Element<T>* First, LinkedList2Element<T>* Last)
	:First(First), Last(Last)
{ 
}

template<typename T>
inline LinkedList2<T> LinkedList2<T>::Copy()
{
	return LinkedList2<T>();
}

template<typename T>
inline LinkedList2Element<T>* LinkedList2<T>::ElementAt(ulong index)
{
	ulong i = 0;
	this->iter_reset();
	while (this->iter_next() && i < index) { index++; }
	if (i < index)
	{
		throw 1;
	}
	else
	{
		return iter_data();
	}
}

template<typename T>
inline T LinkedList2<T>::DataAt(ulong index)
{
	return *(this->ElementAt(index)->data);
}

template<typename T>
inline void LinkedList2<T>::AddElement(T Element)
{
	this->Last->Previous->Next = new LinkedList2Element(new T(Element), this->Last->Prev, this->Last);
	this->Last->Previous = this->Last->Previous->Next;
}

template<typename T>
inline void LinkedList2<T>::AddBlock(Block<T> Block)
{
	Block.iter_reset();
	while (Block.iter_next()) { AddElement(*Block.iter); }
}

template<typename T>
inline void LinkedList2<T>::InsertElement(T Element, ulong index)
{
	LinkedList2Element<T>* N = this->ElementAt(index);
	N->Previous->Next = new LinkedList2Element<T>(new T(Element), N->Previous, N);
	N->Previous = N->Previous->Next;
}

template<typename T>
inline void LinkedList2<T>::InsertBlock(Block<T> Block, ulong index)
{
	throw -69;
}

template<typename T>
inline size_t LinkedList2<T>::Count()
{
	size_t r = 0;
	this->iter_reset();
	while (this->iter_next()) { r++; }
	return r;
}

template<typename T>
inline T LinkedList2<T>::PopElement(unsigned long long int index)
{
	LinkedList2Element<T>* N = this->ElementAt(index);
	N->Previous->Next = N->Next;
	N->Next->Previous = N->Next->Previous;
	T r = *(N->data);
	delete N;
	return r;
}

template<typename T>
inline Block<T> LinkedList2<T>::PopBlock(unsigned long long int index, size_t size)
{
	throw -69;
}
