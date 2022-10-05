#include"main.h"
#define safe false
#pragma once
template<typename T>
class Block
{
public:
	T* Pointer;
	size_t Size;

	inline T* End();

	Block(size_t Size);
	inline Block(T* Pointer, size_t Size);
	
	Block<T> Copy();

	T* ForEach(bool(*F)(T*&), T* start = nullptr, T* end = nullptr);

	inline T* operator[](unsigned long long index);
};

template<typename T>
inline T* Block<T>::End()
{
	return Pointer + Size;
}

template<typename T>
inline Block<T>::Block(size_t Size)
	:Size(Size)
{
	Pointer = new T[Size];
}

template<typename T>
inline Block<T>::Block(T* Pointer, size_t Size)
	: Size(Size), Pointer(Pointer)
{
}

template<typename T>
inline Block<T> Block<T>::Copy()
{
	Block<T> Block(this->Size);
	if (this->Size != Block->Size) { throw 2; }
	for (unsigned long long i = 0; i < this->Size; i++)
	{
		this->Pointer[i] = Block->Pointer[i];
	}
	return Block;
}


template<typename T>
inline T* Block<T>::ForEach(bool(*F)(T*&), T* i, T* end)
{
#if safe
	if (i == nullptr || !(i >= this->Pointer))
	{
		i = this->Pointer;
	}
	if (end == nullptr || !(i < this->End()))
	{
		end = this->End();
	}
#endif
	while ((i < this->End() && i >= this->Pointer) && F(i)) { i++; }
	return (i < this->End() && i >= this->Pointer) ? i : nullptr;
}

template<typename T>
inline T* Block<T>::operator[](unsigned long long index)
{
#if safe
	if (index < this->Size) { throw 1; }
#endif
	return Pointer[index];
}
