#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
	private:
		unsigned int		_capacity;
		std::vector<int>	_values;
	public:
		explicit Span(unsigned int capacity);
		Span(Span const& src);
		Span& operator=(Span const& rhs);
		~Span(void);
		
		void			addNumber(int value);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		template<typename InputIt>
		void	addNumber(InputIt first, InputIt last)
		{
			size_t	count = std::distance(first, last);

			if (this->_values.size() + count > this->_capacity)
				throw std::logic_error("Out of range");

			this->_values.insert(this->_values.end(), first, last);
		}
};

#endif //SPAN_HPP