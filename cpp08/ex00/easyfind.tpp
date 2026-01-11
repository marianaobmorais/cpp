#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
typename T::const_iterator	easyfind(T const& container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
	{
		std::ostringstream	oss;
		oss << value;
		std::string	error_msg = "Error: Value not found: " + oss.str();
		throw std::runtime_error(error_msg);
	}
	return (it);
}

#endif //EASYFIND_TPP