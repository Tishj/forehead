/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Typedef.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 16:24:24 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 13:39:41 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_HPP
# define TYPEDEF_HPP

#include <string>
#include <HeaderData.hpp>

class Typedef : public HeaderData
{
	public:
		Typedef() : HeaderData(OTHER) {}
		Typedef(const Typedef& orig) : HeaderData(OTHER)
		{
			this->data = orig.data;
			this->raw = orig.raw;
		}
		std::pair<std::string, std::string> data;
		std::string print(size_t indent) const
		{
			std::string out;

			out += this->data.first();
			size_t	tabAmount = ((int)(indent - (this->data.first().size() / 4)) < 0) ? 0 : indent - (this->data.first().size() / 4);
			out += std::string(tabAmount, '\t');
			out += this->data.second();
			return (out);
		}
};

#endif
