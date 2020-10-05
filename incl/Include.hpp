/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Include.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 14:37:19 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 16:31:59 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_HPP
# define INCLUDE_HPP

# include <HeaderData.hpp>
# include <string>

class	Include : public HeaderData
{
	public:
		std::string line;
		Include() : HeaderData(INCLUDE) {}
		Include(const Include& orig) : HeaderData(INCLUDE)
		{
			this->line = orig.line;
			this->raw = orig.raw;
		}
		std::string print(size_t indent) const
		{
			(void)indent;
			return (line);
		}
};

#endif
