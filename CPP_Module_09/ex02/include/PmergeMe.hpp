#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>

class PmergeMe {
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		double _vect_time;
		double _deq_time;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);

		void	SortData();

		template <typename T, typename P> T SortAll(T& container, P& pairs);
		template <typename T> void PrintAnyArray(T array);

};

#endif