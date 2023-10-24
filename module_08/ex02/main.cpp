#include "MutantStack.hpp"

int main()
{
	std::cout << "==========[ Mutant Stack ]==========" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "[mt] top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "[mt] size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(5);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << s.top()<< std::endl;
	}
	std::cout << "==========[ Mutant Stack (vec) ]==========" << std::endl;
	{
		MutantStack<int, std::vector<int> > mtv;
		mtv.push(5);
		mtv.push(17);
		std::cout << "[mtv] top: "<< mtv.top() << std::endl;
		mtv.pop();
		std::cout << "[mtv] size: " <<mtv.size() << std::endl;
		mtv.push(3);
		mtv.push(5);
		mtv.push(737);
		mtv.push(0);
		MutantStack<int, std::vector<int> >::iterator it = mtv.begin();
		MutantStack<int, std::vector<int> >::iterator ite = mtv.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;

}