/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Header.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 11:13:32 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 19:26:02 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

#include <iostream>
#include <string>
#include <Function.hpp>
#include <unordered_map>
#include <vector>
#include <Object.hpp>
#include <Other.hpp>
#include <HeaderData.hpp>

class	Header
{
	public:
		std::string	guard;
		std::unordered_map<std::string, Function>	prototypes;
		std::vector<std::string>	includes;
		std::vector<std::string>	misc;
		std::vector<Object>	structs;
		std::vector<std::pair<std::string, std::string> >	tdefs;
		std::vector<Other>	others;
		std::vector<HeaderData*>	data;
		~Header()
		{
//			std::cerr << "CLEANING UP HEADERDATA" << std::endl;
			for (size_t i = 0; i < data.size(); i++)
				delete data[i];
		}
};

#endif
