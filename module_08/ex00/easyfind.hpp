#ifndef _EASYFIND_HPP_
#define _EASYFIND_HPP_

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw "Not found";
	return it;
}

#endif