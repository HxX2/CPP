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
class MutantStack : public std::stack<T>
{

public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

private:
	Container _cont;

public:
	MutantStack() : _cont(){};
	~MutantStack(){};
	MutantStack(const MutantStack &src) : _cont(src._cont){};
	MutantStack &operator=(const MutantStack &src)
	{
		_cont = src._cont;
		return *this;
	};

	void push(T val) { _cont.push_back(val); };
	void pop() { _cont.pop_back(); };
	T top() { return _cont.back(); };
	const T top() const { return _cont.back(); };
	size_t size() const { return _cont.size(); };


	iterator begin() { return _cont.begin(); };
	const_iterator begin() const { return _cont.begin(); };
	iterator end() { return _cont.end(); };
	const_iterator end() const { return _cont.end(); };
	reverse_iterator rbegin() { return _cont.rbegin(); };
	const_reverse_iterator rbegin() const { return _cont.rbegin(); };
	reverse_iterator rend() { return _cont.rend(); };
	const_reverse_iterator rend() const { return _cont.rend(); };
};

#endif