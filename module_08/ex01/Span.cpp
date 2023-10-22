#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::~Span()
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_n = src._n;
		_vec = src._vec;
	}
	return *this;
}

Span::Span(unsigned int n)
{
	_n = n;
}

void Span::addNumber(int n)
{
	if (_vec.size() == _n)
		throw FullSpanException();
	_vec.push_back(n);
}

int Span::shortestSpan() const
{
	std::vector<int> tmp(_vec);
	if (tmp.size() <= 1)
		throw NoSpanException();
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

long Span::longestSpan() const
{
	std::vector<int> tmp(_vec);
	if (tmp.size() <= 1)
		throw NoSpanException();
	std::sort(tmp.begin(), tmp.end());
	return static_cast<long>(tmp[tmp.size() - 1]) - tmp[0];
}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Span is empty or contains only one element";
}
