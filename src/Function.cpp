/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Function.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 15:49:30 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 13:24:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <Function.hpp>

using namespace std;

Function::Function() {};

Function::Function(string ret, string name, vector<string> args) : returnType(ret), name(name), args(args) {};

Function::Function(const Function& funct) : returnType(funct.returnType), name(funct.name), args(funct.args) {};

Function::~Function() {};

ostream&	operator<<(ostream& stream, const Function& funct)
{
	stream << "\n";
	stream << funct.returnType << "\t" << funct.name << "(";
	for (size_t i = 0;i < funct.args.size(); i++)
	{
		stream << funct.args[i];
		if (i + 1 < funct.args.size())
			stream << ", ";
	}
	stream << ")";
	return (stream);
}
