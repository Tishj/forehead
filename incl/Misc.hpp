/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Misc.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 16:19:44 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 13:38:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_HPP
# define MISC_HPP

#include <string>
#include <HeaderData.hpp>

class Misc : public HeaderData
{
	public:
		Misc() : HeaderData(MISC) {}
		Misc(const Misc& orig) : HeaderData(MISC)
		{
			this->line = orig.line;
			this->raw = orig.raw;
		}
		std::string line;
		std::string print(size_t indent) const
		{
			(void)indent;
			return (line);
		}
};

#endif
