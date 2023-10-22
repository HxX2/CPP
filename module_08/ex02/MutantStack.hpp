#ifndef _MUTANTSTACK_HPP_
#define _MUTANTSTACK_HPP_

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

public:
	MutantStack() {};
	~MutantStack(){};
	MutantStack(const MutantStack &src)  { *this = src; };
	MutantStack &operator=(const MutantStack &src)
	{
		this->std::stack<T, Container>::operator=(src);
		return *this;
	};

	void push(T val) { this->c.push_back(val); };
	void pop() { this->c.pop_back(); };
	T top() { return this->c.back(); };
	const T top() const { return this->c.back(); };
	size_t size() const { return this->c.size(); };


	iterator begin() { return this->c.begin(); };
	const_iterator begin() const { return this->c.begin(); };
	iterator end() { return this->c.end(); };
	const_iterator end() const { return this->c.end(); };
	reverse_iterator rbegin() { return this->c.rbegin(); };
	const_reverse_iterator rbegin() const { return this->c.rbegin(); };
	reverse_iterator rend() { return this->c.rend(); };
	const_reverse_iterator rend() const { return this->c.rend(); };
};

#endif