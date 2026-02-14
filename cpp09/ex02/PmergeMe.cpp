#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &src) : _vector(src._vector), _deque(src._deque) {}

PmergeMe&	PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_vector = rhs._vector;
		this->_deque = rhs._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

static int	parseInt(char const *str)
{
	char	*endPtr;
	long	n;

	n = std::strtol(str, &endPtr, 10);
	if (*endPtr != '\0' || n <= 0 || n > INT_MAX)
		throw std::logic_error("Error");
	return (static_cast<int>(n));
}

void	PmergeMe::addNumber(char const *arg)
{
	int	n = parseInt(arg);

	this->_vector.push_back(n);
	this->_deque.push_back(n);
}

void	PmergeMe::printElapsedTimes(double vectorTime, double dequeTime) const
{
	std::cout << "Time to process a range of "
				<< this->_vector.size()
				<< " elements with std::vector : "
				<< vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of "
				<< this->_deque.size()
				<< " elements with std::deque : "
				<< dequeTime << " us" << std::endl;
}


void	PmergeMe::printNumbers(bool before) const
{
	if (before)
		std::cout << "Before:";
	else
		std::cout << "After:";

	std::vector<int>::const_iterator it = this->_vector.begin();
	while (it != this->_vector.end())
		std::cout << ' ' << *it++;
	std::cout << std::endl;
}


void	PmergeMe::process()
{
	this->printNumbers(true);

	clock_t startVector = clock();
	this->sortVector(this->_vector);
	clock_t	endVector = clock();

	clock_t startDeque = clock();
	this->sortDeque(this->_deque);
	clock_t	endDeque = clock();

	double	vectorTime = static_cast<double>(endVector - startVector)
						/ CLOCKS_PER_SEC * 1000000;
	double	dequeTime = static_cast<double>(endDeque - startDeque)
						/ CLOCKS_PER_SEC * 1000000;

	this->printNumbers(false);
	this->printElapsedTimes(vectorTime, dequeTime);
}

std::vector<size_t>		PmergeMe::buildJacobsthalOrder(size_t n) const
{
	std::vector<size_t>	order;

	if (n == 0)
		return (order);

	std::vector<size_t>	jacobNumbers;
	jacobNumbers.push_back(0);
	jacobNumbers.push_back(1);

	while (jacobNumbers.back() < n)
	{
		size_t size = jacobNumbers.size();
		jacobNumbers.push_back(jacobNumbers[size - 1] + 2 * jacobNumbers[size - 2]);
	}

	size_t	prev = 1;

	for (size_t i = 2; i < jacobNumbers.size(); ++i)
	{
		size_t	curr = jacobNumbers[i];
		if (curr > n)
			curr = n;

		for (size_t j = curr; j > prev; --j)
			order.push_back(j - 1);

		prev = curr;
		if (curr == n)
			break ;
	}
	return (order);
}

void	PmergeMe::sortVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return ;

	std::vector< std::pair<int, int> >	pairs;
	std::vector<int>	mainChain;
	std::vector<int>	pendingMins;

	int	leftover = 0;
	bool	hasLeftover = false;

	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (i + 1 < vec.size())
		{
			int	first = vec[i];
			int	second = vec[i + 1];

			if (first < second)
				pairs.push_back(std::make_pair(first, second));
			else
				pairs.push_back(std::make_pair(second, first));
		}
		else
		{
			leftover = vec[i];
			hasLeftover = true;
		}
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].second);
		pendingMins.push_back(pairs[i].first);
	}

	this->sortVector(mainChain);

	std::cout << "Main chain: ";
    for (std::vector<int>::const_iterator it = mainChain.begin(); it != mainChain.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\nPending mins: ";
    for (std::vector<int>::const_iterator it = pendingMins.begin(); it != pendingMins.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
	std::cout << std::endl;


	std::vector<size_t>	order = buildJacobsthalOrder(pendingMins.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int	number = pendingMins[order[i]];
		std::vector<int>::iterator	pos = std::lower_bound(mainChain.begin(), mainChain.end(), number);
		mainChain.insert(pos, number);
	}

	if (hasLeftover)
	{
		std::vector<int>::iterator	pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	vec = mainChain;
}

void	PmergeMe::sortDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return ;

	std::deque< std::pair<int, int> >	pairs;
	std::deque<int>	mainChain;
	std::deque<int>	pendingMins;

	int	leftover = 0;
	bool	hasLeftover = false;

	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (i + 1 < deq.size())
		{
			int	x = deq[i];
			int	y = deq[i + 1];

			if (x < y)
				pairs.push_back(std::make_pair(x, y));
			else
				pairs.push_back(std::make_pair(y, x));
		}
		else
		{
			leftover = deq[i];
			hasLeftover = true;
		}
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].second);
		pendingMins.push_back(pairs[i].first);
	}

	this->sortDeque(mainChain);

	std::vector<size_t>	order = buildJacobsthalOrder(pendingMins.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int	number = pendingMins[order[i]];
		std::deque<int>::iterator	pos = std::lower_bound(mainChain.begin(), mainChain.end(), number);
		mainChain.insert(pos, number);
	}

	if (hasLeftover)
	{
		std::deque<int>::iterator	pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	deq = mainChain;
}
