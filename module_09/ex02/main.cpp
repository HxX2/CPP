#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

void print_vector(std::vector<int> &vec);

std::vector<int> gen_jacob_seq(size_t n)
{
	std::vector<int> seq;
	seq.push_back(0);
	seq.push_back(1);
	for (size_t i = 2; i < n - 1; i++)
		seq.push_back(seq[i - 1] + 2 * seq[i - 2]);
	seq.erase(seq.begin(), seq.begin() + 3);
	return seq;
}

void sort_pairs(std::vector<int> &unsorted)
{
	for (size_t i = 0; i < unsorted.size(); i += 2)
	{
		if (unsorted[i] > unsorted[i + 1])
			std::swap(unsorted[i], unsorted[i + 1]);
	}
}

void swap_pairs(std::vector<int> &unsorted)
{
	for (size_t i = 1; i < unsorted.size(); i += 2)
	{
		int j = i;
		while (j > 0 && unsorted[j] < unsorted[j - 2])
		{
			std::swap(unsorted[j], unsorted[j - 2]);
			std::swap(unsorted[j - 3], unsorted[j - 1]);
			j -= 2;
		}
	}
}

void print_vector(std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
		// if (i % 2 == 1)
			// std::cout << "| ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> unsorted;

	unsorted.push_back(6);
	unsorted.push_back(5);
	unsorted.push_back(4);
	unsorted.push_back(8);
	unsorted.push_back(2);
	unsorted.push_back(3);
	unsorted.push_back(7);
	unsorted.push_back(1);

	sort_pairs(unsorted);
	swap_pairs(unsorted);

	std::vector<int> S;
	std::vector<int> pend;
	std::vector<int> jacob_seq = gen_jacob_seq(unsorted.size());

	for (size_t i = 0; i < unsorted.size(); i++)
	{
		if (i % 2 == 0)
			pend.push_back(unsorted[i]);
		else
			S.push_back(unsorted[i]);
	}

	S.insert(S.begin(), pend[0]);
	pend.erase(pend.begin());

	for (size_t i = 0; i < pend.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend[i]);
		S.insert(it, pend[i]);
	}
	pend.clear();

	print_vector(S);
	print_vector(pend);

	return 0;
}
