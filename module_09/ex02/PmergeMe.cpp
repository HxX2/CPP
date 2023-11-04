#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		if (av[i][0] == '-' || av[i][0] == '+' || !std::isdigit(av[i][0]))
			throw std::invalid_argument("Invalid argument");

		this->_vec.push_back(atoi(av[i]));
		this->_deq.push_back(atoi(av[i]));
	}
	
	if (_vec.size() % 2 != 0)
	{
		_vec_stager = _vec[_vec.size() - 1];
		_vec.pop_back();
		_deq_stager = _deq[_deq.size() - 1];
		_deq.pop_back();
	}
	else
	{
		_vec_stager = -1;
		_deq_stager = -1;
	}
}

PmergeMe::~PmergeMe()
{
	_vec.clear();
	_deq.clear();
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
	*this = src;	
}

PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		this->_vec = src._vec;
		this->_deq = src._deq;
	}
	return *this;
}

void PmergeMe::vector_sort()
{
	std::cout << "Before sort: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	if (_vec_stager != -1)
		std::cout << _vec_stager;
	std::cout << std::endl;

	clock_t start = clock();
	sort_pairs(VEC);
	swap_pairs(VEC);
	sorted_merge(VEC);
	jacob_bs(VEC);
	clock_t stop = clock();

	std::cout << "After sort: ";
	for (size_t i = 0; i < _S_v.size(); i++)
		std::cout << _S_v[i] << " ";
	std::cout << std::endl;

	double duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;

	std::cout << "Time taken by vector sort: " << std::fixed << std::setprecision(6) << duration << " μs" << std::endl;	
}

void PmergeMe::deque_sort()
{
	std::cout << "Before sort: ";
	for (size_t i = 0; i < _deq.size(); i++)
		std::cout << _deq[i] << " ";
	if (_deq_stager != -1)
		std::cout << _deq_stager;
	std::cout << std::endl;
	
	clock_t start = clock();
	sort_pairs(DEQ);
	swap_pairs(DEQ);
	sorted_merge(DEQ);
	jacob_bs(DEQ);
	clock_t stop = clock();

	std::cout << "After sort: ";
	for (size_t i = 0; i < _S_d.size(); i++)
		std::cout << _S_d[i] << " ";
	std::cout << std::endl;

	double duration = static_cast<double>(stop - start) / CLOCKS_PER_SEC;

	std::cout << "Time taken by deque sort: " << std::fixed << std::setprecision(6) << duration << " μs" << std::endl;
}

void PmergeMe::gen_jacob_seq(size_t n)
{
	if (n < 3)
		return;
	_jacobs.clear();
	_jacobs.push_back(0);
	_jacobs.push_back(1);
	for (size_t i = 2; i < n - 1; i++)
		_jacobs.push_back(_jacobs[i - 1] + 2 * _jacobs[i - 2]);
	
	_jacobs.erase(_jacobs.begin(), _jacobs.begin() + 3);
}

void PmergeMe::sort_pairs(int type)
{
	if (type == VEC)
	{
		for (size_t i = 0; i < _vec.size(); i += 2)
		{
			if (_vec[i] > _vec[i + 1])
				std::swap(_vec[i], _vec[i + 1]);
		}
	}
	else if (type == DEQ)
	{
		for (size_t i = 0; i < _deq.size(); i += 2)
		{
			if (_deq[i] > _deq[i + 1])
				std::swap(_deq[i], _deq[i + 1]);
		}
	}
}

void PmergeMe::swap_pairs(int type)
{
	if (type == VEC)
	{
		for (size_t i = 1; i < _vec.size(); i += 2)
		{
			int j = i;
			while (j > 0 && j - 2 > 0 && _vec[j] < _vec[j - 2])
			{
				std::swap(_vec[j], _vec[j - 2]);
				std::swap(_vec[j - 3], _vec[j - 1]);
				j -= 2;
			}
		}
	}
	else if (type == DEQ)
	{
		for (size_t i = 1; i < _deq.size(); i += 2)
		{
			int j = i;
			while (j > 0 && j - 2 > 0 && _deq[j] < _deq[j - 2])
			{
				std::swap(_deq[j], _deq[j - 2]);
				std::swap(_deq[j - 3], _deq[j - 1]);
				j -= 2;
			}
		}
	}
}

void PmergeMe::sorted_merge(int type)
{
	if (type == VEC)
	{
		for (size_t i = 0; i < _vec.size(); i++)
		{
			if (i % 2 == 0)
				_pend_v.push_back(_vec[i]);
			else
				_S_v.push_back(_vec[i]);
		}

		_S_v.insert(_S_v.begin(), _pend_v[0]);
		_pend_v.erase(_pend_v.begin());
		if (_vec_stager != -1)
			_pend_v.push_back(_vec_stager);

		gen_jacob_seq(_pend_v.size());
	}
	else if (type == DEQ)
	{		
		for (size_t i = 0; i < _deq.size(); i++)
		{
			if (i % 2 == 0)
				_pend_d.push_back(_deq[i]);
			else
				_S_d.push_back(_deq[i]);
		}

		_S_d.insert(_S_d.begin(), _pend_d[0]);
		_pend_d.erase(_pend_d.begin());
		if (_deq_stager != -1)
			_pend_d.push_back(_deq_stager);

		gen_jacob_seq(_pend_d.size());
	}
}

void PmergeMe::jacob_bs(int type)
{
	if (type == VEC)
	{
		std::vector<int>::iterator it;
		int jc = 0;
		for (size_t i = 0; i < _pend_v.size(); i++)
		{
			int num = _pend_v[i];

			if (!_jacobs.empty() && std::find(_jacobs.begin(), _jacobs.end(), i + 1) != _jacobs.end())
			{
				num = _pend_v[_jacobs[jc] - 1];
				jc++;
			}
			it = std::lower_bound(_S_v.begin(), _S_v.end(), num);
			_S_v.insert(it, num);
		}
		_pend_v.clear();
	}
	else if (type == DEQ)
	{
		std::deque<int>::iterator it;
		int jc = 0;
		for (size_t i = 0; i < _pend_d.size(); i++)
		{
			int num = _pend_d[i];

			if (!_jacobs.empty() && std::find(_jacobs.begin(), _jacobs.end(), i + 1) != _jacobs.end())
			{
				num = _pend_d[_jacobs[jc] - 1];
				jc++;
			}
			it = std::lower_bound(_S_d.begin(), _S_d.end(), num);
			_S_d.insert(it, num);
		}
		_pend_d.clear();
	}
}
