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

int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw NoSpanException();
	std::sort(_vec.begin(), _vec.end());
	int min = _vec[1] - _vec[0];
	for (unsigned int i = 1; i < _vec.size(); i++)
	{
		if (_vec[i] - _vec[i - 1] < min)
			min = _vec[i] - _vec[i - 1];
	}
	return min;
}

int Span::longestSpan()
{
	if (_vec.size() <= 1)
		throw NoSpanException();
	std::sort(_vec.begin(), _vec.end());
	return _vec[_vec.size() - 1] - _vec[0];
}

const char *Span::FullSpanException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Span is empty or contains only one element";
}
