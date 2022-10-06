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

	inline bool operator ==(LinkedList2Element<T>& other);
	inline bool operator !=(LinkedList2Element<T>& other);
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

template<typename T>
inline bool LinkedList2Element<T>::operator==(LinkedList2Element<T>& other)
{
	return (this->data == other.data) && (this->Next == other.Next) && (this->Previous == other.Previous);
}

template<typename T>
inline bool LinkedList2Element<T>::operator!=(LinkedList2Element<T>& other)
{
	return !(this->operator==(other));
}
