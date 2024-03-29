#ifndef _SPAN_HPP_
#define _SPAN_HPP_

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

class Span
{
private:
	unsigned int _n;
	std::vector<int> _vec;

public:
	Span();
	~Span();
	Span(const Span &src);
	Span &operator=(const Span &src);
	Span(unsigned int n);

	void addNumber(int n);
	int shortestSpan() const;
	long longestSpan() const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		if (_vec.size() + std::distance(begin, end) > _n)
			throw FullSpanException();
		_vec.insert(_vec.end(), begin, end);
	}

	class FullSpanException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif