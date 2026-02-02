#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>

class RPN
{
	private:
		std::stack<int>	_elements;
	public:
		RPN();
		RPN(RPN const& src);
		RPN& operator=(RPN const& rhs);
		~RPN();

		void	process_elements(std::string args);
};

#endif //RPN_HPP