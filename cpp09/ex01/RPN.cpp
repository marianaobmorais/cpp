#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const& src) : _elements(src._elements) {}

RPN& RPN::operator=(RPN const& rhs)
{
	if (this != &rhs)
		this->_elements = rhs._elements;
	return (*this);
}

RPN::~RPN() {}

void	RPN::process_elements(std::string args)
{
	std::istringstream	in(args);
	std::string			token;

	while (in >> token)
	{
		if (token.length() == 1 && isdigit(static_cast<unsigned char>(token[0])))
			this->_elements.push(token[0] - '0');
		else if (token.length() == 1
				&& (token[0] == '+' || token[0] == '-'
				|| token[0] == '*' || token[0] == '/'))
		{
			if (this->_elements.size() >= 2)
			{
				int	rhs = this->_elements.top();
				this->_elements.pop();
				int	lhs = this->_elements.top();
				this->_elements.pop();

				int	result;
				switch(token[0])
				{
					case '+': result = lhs + rhs; break;
					case '-': result = lhs - rhs; break;
					case '*': result = lhs * rhs; break;
					case '/':
						if (rhs == 0)
							throw std::logic_error("Error");
						result = lhs / rhs;
						break;
				}
				this->_elements.push(result);
			}
			else
				throw std::logic_error("Error");
		}
		else
			throw std::logic_error("Error");
	}
	if (this->_elements.size() != 1)
		throw std::logic_error("Error");
	std::cout << this->_elements.top() << std::endl;
}
