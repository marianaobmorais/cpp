/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaoli <mariaoli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:59:05 by mariaoli          #+#    #+#             */
/*   Updated: 2025/05/17 00:08:35 by mariaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cerrno>

bool	checkFileStream(std::ios &stream);
void	replace(std::ifstream &infile, std::ofstream &outfile, const std::string &s1, const std::string &s2);

#endif //UTILS_HPP