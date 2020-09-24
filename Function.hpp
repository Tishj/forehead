/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Function.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 15:46:52 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 13:21:48 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_HPP
# define FUNCTION_HPP

#include <iostream>
#include <string>
#include <vector>

class	Function
{
	public:
		Function();
		Function(std::string ret, std::string name, std::vector<std::string> args);
		Function(const Function& funct);
		~Function();
		std::string	returnType;
		std::string	name;
		std::vector<std::string>	args;
};

std::ostream&	operator<<(std::ostream& stream, const Function& funct);

#endif
