/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Enum.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 10:35:26 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/26 13:04:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_HPP
# define ENUM_HPP

#include <iostream>
#include <string>
#include <vector>

class	Enum
{
	public:
		std::string	name;
		std::vector<std::string>	elements;
		std::string	tdef;
		std::string	print(size_t indent)
		{
			std::string out;
			if (this->tdef.size())
				out += "typedef ";
			out += "enum";
			out += std::string(indent - (out.size() / 4), '\t');
			out += this->name + "\n{\n";
			for (size_t j = 0; j < this->elements.size() ; j++)
				out += "\t" + this->elements[j] + "\n";
			out += "};";
			if (this->tdef.size())
				out += "\t" + this->tdef;
			out += "\n";
			return (out);
		};
};

#endif
