#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &A,T &B)
{
	T temp = A;
	A = B;
	B = temp;
}

template <typename T>
T min(const T &A,const T &B)
{
	return (A < B ? A : B);
}

template <typename T>
T max(const T &A,const T &B)
{
	return (A > B ? A : B);
}

#endif