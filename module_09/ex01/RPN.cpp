#include "RPN.hpp"

void RPN::print_stack(std::stack<int> stack)
{
	std::cout << "stack: " << std::endl;
	while (!stack.empty())
	{
		std::cout << "        │ " << stack.top() << " │" << std::endl;
		stack.pop();
	}
	std::cout << "        └───┘" << std::endl;
}

RPN::RPN()
{
}

RPN::RPN(std::string input)
{
	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (!std::isdigit(*it) && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it != ' ')
			throw std::runtime_error("Error: invalid input");
	}
	_input = input;
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	(void)src;
	return (*this);
}

int RPN::calculate()
{
	std::stack<int> stack;

	std::stringstream ss(_input);
	std::string token;

	while (std::getline(ss, token, ' '))
	{
		if (std::isdigit(token[0]) || ((token[0] == '-' || token[0] == '+') && std::isdigit(token[1])))
			stack.push(stoi(token));
		else
		{
			if (stack.size() >= 2)
			{
				int a = stack.top();
				stack.pop();
				int b = stack.top();
				stack.pop();
				stack.push(doop(a, b, token));
			}
		}
	}

	if (stack.size() != 1)
	{
		print_stack(stack);
		throw std::runtime_error("Error: invalid notation");
	}
	return (stack.top());
}

int RPN::doop(int a, int b, std::string op)
{
	if (op == "+")
		return (b + a);
	else if (op == "-")
		return (b - a);
	else if (op == "*")
		return (b * a);
	else if (op == "/")
	{
		if (a == 0)
			throw std::runtime_error("Error: division by zero");
		return (b / a);
	}
	return (0);
}

int RPN::stoi(std::string str)
{
	std::stringstream ss(str);
	int num;
	ss >> num;
	return (num);
}
