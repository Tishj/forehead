/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Head.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 14:37:19 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 16:44:08 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_HPP
# define HEAD_HPP

# include <HeaderData.hpp>
# include <string>
# include <vector>

class	Head : public HeaderData
{
	public:
		std::vector<std::string>	header;
		Head() : HeaderData(HEAD) {}
		Head(const Head& orig) : HeaderData(HEAD)
		{
			this->header = orig.header;
			this->raw = orig.raw;
		}
		std::string print(size_t indent) const
		{
			std::string out;

			(void)indent;
			for (size_t i = 0; i < this->header.size(); i++)
			{
				out += this->header[i];
				if (i + 1 < this->header.size())
					out += "\n";
			}
			return (out);
		}
};

#endif
