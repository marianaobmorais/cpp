#ifndef PMERGEME_HPP
# define PMERGEME_HPP 

#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		
		void				sortVector(std::vector<int> &vec);
		void				sortDeque(std::deque<int> &deq);
		std::vector<size_t>	buildJacobsthalOrder(size_t n) const;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe&			operator=(PmergeMe const &rhs);
		~PmergeMe();
		
		void				addNumber(char const *arg);
		void				process();
		void				printNumbers(bool before) const;
		void				printElapsedTimes(double vectorTime, double dequeTime) const;
	};
#endif //PMERGEME_HPP