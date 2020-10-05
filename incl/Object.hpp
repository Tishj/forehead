/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Object.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 15:58:19 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/05 13:28:08 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_HPP
# define OBJECT_HPP

#include <string>
#include <vector>
#include <HeaderData.hpp>

class	Object : public HeaderData
{
	public:
		Object() : HeaderData(OBJECT) {}
		Object(const Object& orig) : HeaderData(OBJECT)
		{
			this->elements = orig.elements;
			this->name = orig.name;
			this->type = orig.type;
			this->tdef = orig.tdef;
			this->raw = orig.raw;
		}
		std::string	name;
		std::string type;
		std::string	tdef;
		std::vector<std::pair<std::string, std::string>>	elements;
		Object(std::string name, std::string type, std::string tdef, std::vector<std::pair<std::string, std::string> > elements) : HeaderData(OBJECT), name(name), type(type), tdef(tdef), elements(elements) {} ;
		~Object() {} ;
		std::string print(size_t indent) const
		{
			std::string out;
			if (this->tdef.size())
				out += "typedef ";
			out += this->type;
			size_t	tabAmount = ((int)(indent - (out.size() / 4)) < 0) ? 0 : indent - (out.size() / 4);
			out += std::string(tabAmount, '\t');
			out += this->name + "\n{\n";
			for (size_t j = 0; j < this->elements.size() ; j++)
			{
				out += "\t" + this->elements[j].first;
				if (type.compare("enum"))
				{
					tabAmount = ((int)(indent - 1 - (this->elements[j].first.size() / 4)) < 0) ? 0 : indent - 1 - (this->elements[j].first.size() / 4);
					out += std::string(indent - 1 - (this->elements[j].first.size() / 4), '\t');
					out += this->elements[j].second;
				}
				out += "\n";
			}
			out += "}";
			if (this->tdef.size())
			{
				out += std::string(indent, '\t') + this->tdef;
			}
			else
				out += ";";
			return (out);
		}
};

#endif
