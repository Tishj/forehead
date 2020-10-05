/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Comment.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 14:46:21 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 17:21:30 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMENT_HPP
# define COMMENT_HPP

# include <HeaderData.hpp>
# include <string>
# include <vector>

class Comment : public HeaderData
{
	public:
		std::vector<std::string>	lines;
		Comment() : HeaderData(COMMENT) {}
		Comment(const Comment& orig) : HeaderData(COMMENT)
		{
			this->lines = orig.lines;
			this->raw = orig.raw;
		}
		std::string print(size_t indent) const
		{
			std::string out = "/*\n";
			for (size_t i = 0; i < lines.size(); i++)
			{
				out += "**";
				out += std::string(indent, '\t');
				out += lines[i] + "\n";
			}
			out += "*/";
			return (out);
		}
};

#endif
