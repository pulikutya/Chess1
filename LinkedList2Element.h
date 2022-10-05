#include"main.h"
#pragma once
template<typename T>
class LinkedList2Element
{
	LinkedList2Element<T>* Previous;
	T data;
	LinkedList2Element<T*> Next;

	LinkedList2Element(T data, LinkedList2Element<T>* Previous = nullptr, LinkedList2Element<T>* Next = nullptr);

	inline bool PreviousNullptr();
	inline bool NextNullptr();
};

template<typename T>
inline LinkedList2Element<T>::LinkedList2Element(T data, LinkedList2Element<T>* Previous, LinkedList2Element<T>* Next)
	:data(data), Next(Next), Previous(Previous)
{
}

template<typename T>
inline bool LinkedList2Element<T>::PreviousNullptr()
{
	return Previous == nullptr;
}

template<typename T>
inline bool LinkedList2Element<T>::NextNullptr()
{
	return Next == nullptr;
}
