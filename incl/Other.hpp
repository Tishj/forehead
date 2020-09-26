/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Other.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 10:59:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/26 19:18:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_HPP
# define OTHER_HPP

#include <iostream>
#include <string>

class	Other
{
	public:
		std::string	type;
		std::string	name;
		std::string print(size_t indent)
		{
			std::string out;

			size_t	tabAmount = ((int)(indent - (type.size() / 4)) < 0) ? 0 : indent - (type.size() / 4);
			out += this->type + std::string(tabAmount, '\t') + this->name;
			return (out);
		}
};

#endif
