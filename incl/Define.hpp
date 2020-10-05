/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Define.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 14:37:19 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 16:32:19 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_HPP
# define DEFINE_HPP

# include <HeaderData.hpp>
# include <string>

class	Define : public HeaderData
{
	public:
		std::string line;
		Define() : HeaderData(DEFINE) {}
		Define(const Define& orig) : HeaderData(DEFINE)
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
