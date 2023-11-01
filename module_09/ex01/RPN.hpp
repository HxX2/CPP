#ifndef _RPN_HPP_
# define _RPN_HPP_

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <exception>


class RPN
{
	private:
		std::string _input;

		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		int doop(int a, int b, std::string op);
		int stoi(std::string str);
		void print_stack(std::stack<int> stack);
	public:
		RPN(std::string input);
		~RPN();
		int calculate();
		
};

#endif