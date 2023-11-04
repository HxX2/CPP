#ifndef _PMERGEME_HPP_
# define _PMERGEME_HPP_

# define VEC 1
# define DEQ 0

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	private:
		int _vec_stager;
		std::vector<int> _vec;
		std::vector<int> _pend_v;
		std::vector<int> _S_v;

		int _deq_stager;
		std::deque<int> _deq;
		std::deque<int> _pend_d;
		std::deque<int> _S_d;
		
		std::vector<int> _jacobs;

		void gen_jacob_seq(size_t n);
		void sort_pairs(int type);
		void swap_pairs(int type);
		void jacob_bs(int type);
		void sorted_merge(int type);

		PmergeMe();
		PmergeMe(const PmergeMe& src);
		PmergeMe& operator=(const PmergeMe& src);
	public:
		PmergeMe(char **av);
		~PmergeMe();
		
		void vector_sort();
		void deque_sort();		
};

#endif