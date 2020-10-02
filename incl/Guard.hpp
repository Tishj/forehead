/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Guard.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 14:37:19 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 16:32:07 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUARD_HPP
# define GUARD_HPP

# include <HeaderData.hpp>
# include <string>

class	Guard : public HeaderData
{
	public:
		std::string line;
		Guard() : HeaderData(GUARD) {}
		Guard(const Guard& orig) : HeaderData(GUARD)
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
