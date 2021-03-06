/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Other.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 10:59:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 13:39:30 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_HPP
# define OTHER_HPP

#include <iostream>
#include <string>
#include <HeaderData.hpp>

class	Other : public HeaderData
{
	public:
		Other() : HeaderData(OTHER) {}
		Other(const Other& orig) : HeaderData(OTHER)
		{
			this->type = orig.type;
			this->name = orig.name;
			this->raw = orig.raw;
		}
		std::string	type;
		std::string	name;
		std::string print(size_t indent) const
		{
			std::string out;

			size_t	tabAmount = ((int)(indent - (type.size() / 4)) < 0) ? 0 : indent - (type.size() / 4);
			out += this->type + std::string(tabAmount, '\t') + this->name;
			return (out);
		}
};

#endif
