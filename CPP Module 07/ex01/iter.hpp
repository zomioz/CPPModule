#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename F>
void iter(T &Array, size_t lenght, F f)
{
	for (size_t x = 0; x < lenght; x++)
	{
		f(Array[x]);
	}
}

template <typename T>
void incrementation(T &x)
{
	x++;
}

template <typename T>
void change_word(T &x)
{
	x = "World";
}

template <typename T>
void my_print(const T &x)
{
	std::cout << " " << x;
}

#endif