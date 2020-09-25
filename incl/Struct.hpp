/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Struct.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 15:58:19 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/25 15:58:54 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <vector>

class	Struct
{
	public:
		Struct() {} ;
		Struct(std::string name, std::string tdef, std::vector<std::pair<std::string, std::string>> elements) : name(name), tdef(tdef), elements(elements) {} ;
		~Struct() {} ;
		std::vector<std::pair<std::string, std::string>>	elements;
		std::string	name;
		std::string	tdef;
};
