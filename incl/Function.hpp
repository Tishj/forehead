/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Function.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 15:46:52 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/26 19:17:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_HPP
# define FUNCTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>

class	Function
{
	public:
		Function();
		Function(std::string ret, std::string name, std::vector<std::string> args);
		Function(const Function& funct);
		~Function();
		std::string	returnType;
		std::string	name;
		std::vector<std::string>	args;
		std::string	print(size_t indent)
		{
			std::string out;

			out += this->returnType;
			size_t	tabAmount = ((int)(indent - (this->returnType.size() / 4)) < 0) ? 0 : indent - (this->returnType.size() / 4);
			out += std::string(tabAmount, '\t');
			out += this->name + "(";
			size_t	lineSize = (indent * 4) + this->name.size() + 1;
			if (this->args.size() && lineSize + this->args[0].size() >= 80)
			{
				out += "\n" + std::string(indent, '\t');
				lineSize = (indent * 4);
			}
			for (size_t i = 0; i < this->args.size(); i++)
			{
				if (lineSize + this->args[i].size() + ((i + 1 == this->args.size()) ? 2 : 1) >= 80)
				{
					std::cerr << "ERROR: " << out << " | " << this->args[i] << std::endl; 
					throw (std::runtime_error("Unable to create a NORME compliant line"));
				}
				out += this->args[i];
				bool	startNewLine = (i + 1 < this->args.size() && lineSize + this->args[i].size() + 2 + this->args[i + 1].size() + 2 >= 80);
				lineSize += this->args[i].size();
				if (startNewLine)
				{
					out += ",\n" + std::string(indent, '\t');
					lineSize = (indent * 4);
				}
				else if (i + 1 != this->args.size())
				{
					out += ", ";
					lineSize += 2;
				}
			}
			out += ");";
			return (out);
		}
};

#endif
