/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Other.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 10:59:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/26 12:53:57 by tbruinem      ########   odam.nl         */
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

			out += this->type + std::string(indent - (type.size() / 4), '\t') + this->name;
			return (out);
		}
};

#endif
