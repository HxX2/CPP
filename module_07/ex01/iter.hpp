#ifndef _ITER_HPP_
#define _ITER_HPP_

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}
#endif