#include "Span.hpp"
#include <stdexcept>
#include <iterator>

Span::Span(unsigned int capacity) : _capacity(capacity) {}

Span::Span(Span const& src) : _capacity(src._capacity), _values(src._values) {}

Span& Span::operator=(Span const& rhs)
{
	if (this != &rhs)
	{
		this->_capacity = rhs._capacity;
		this->_values = rhs._values;
	}
	return (*this);
}

Span::~Span(void) {}

void	Span::addNumber(int value)
{
	if (this->_values.size() >= this->_capacity)
		throw std::logic_error("Out of range");
	this->_values.push_back(value);
}

unsigned int	Span::shortestSpan() const
{
	if (this->_values.size() < 2)
		throw std::logic_error("Not enough values");

	std::vector<int> tmp_values = this->_values;
	std::sort(tmp_values.begin(), tmp_values.end());

	int	result = tmp_values[1] - tmp_values[0];
	for (std::vector<int>::size_type i = 1; i + 1 < tmp_values.size(); i++)
	{
		int	diff = tmp_values[i + 1] - tmp_values[i];
		if (diff < result)
			result = diff;
	}
	return (static_cast<unsigned int>(result));
}

unsigned int	Span::longestSpan() const
{
	if (this->_values.size() < 2)
		throw std::logic_error("Not enough values");
	std::vector<int>::const_iterator min = std::min_element(this->_values.begin(), this->_values.end());
	std::vector<int>::const_iterator max = std::max_element(this->_values.begin(), this->_values.end());

	int diff = *max - *min;
	return (static_cast<unsigned int>(diff));
}