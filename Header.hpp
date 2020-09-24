/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Header.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 11:13:32 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 11:50:35 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

#include <iostream>
#include <string>
#include <Function.hpp>
#include <unordered_map>
#include <vector>

class	Header
{
	public:
		std::string	guard;
		std::unordered_map<std::string, Function>	prototypes;
		size_t	indent;
		std::vector<std::string>	includes;
		std::vector<std::string>	misc;
};

std::ostream&	operator>>(std::ostream& stream, Header head);

#endif
