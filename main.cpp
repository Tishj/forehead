/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 21:53:16 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 13:33:39 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <Function.hpp>

#define NAME "hardhat"
//#define NAME "headsup"
//#define NAME "ahead"

using namespace std;

string	usage()
{
	string out;

	out += "Usage: hardhat [OPTION]... [input-files]...";
	return (out);
}

int	error(string errmsg)
{
	cerr << errmsg << endl;
	return (1);
}

bool	test_regex(ifstream& file, string buf, Function& funct)
{
	regex	prototype("^([^\\t]+)[\\t]+(.*)\\(([^\\)]*)");
	smatch	prot_res;
	if (!regex_search(buf, prot_res, prototype))
		return (false);
	funct.returnType = prot_res.str(1);
	funct.name = prot_res.str(2);
//	cerr << prot_res.str(1) << " | " << prot_res.str(2) << " | " << prot_res.str(3) << " | " << prot_res.suffix().str() << endl;
	string funct_args = prot_res.str(3);
	string remainder = prot_res.suffix().str();
	if (!remainder.size())
	{
		while (getline(file, buf))
		{
			funct_args += buf;
			if (buf.find(')') != string::npos || file.eof())
				break ;
		}
	}
	regex	arg("[\\t]*([^\\(\\)\\t\\ ,]+\\ +[^\\(\\)\\t\\ ,]+)(?:\\,?[\\ ]*)");
	smatch	arg_res;
	vector<string>	args;
	while (regex_search(funct_args, arg_res, arg, regex_constants::match_any))
	{
		args.push_back(arg_res.str(1));
		funct_args = arg_res.suffix().str();
	}
//	for (size_t i = 0; i < args.size(); i++)
//		cout << args[i] << endl;
	funct.args = args;
	return (true);
}

void	test_prototype(string name)
{
	ifstream	file(name.c_str());
	string		buf;
	vector<Function>	functions;

	while (getline(file, buf))
	{
		Function tmp;
		if (test_regex(file, buf, tmp))
			functions.push_back(tmp);
		if (file.eof())
			break ;
	}
	for (size_t i = 0; i < functions.size(); i++)
		cout << functions[i];
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (error(usage()));
	test_prototype("prototype0");
	test_prototype("prototype1");
	test_prototype("prototype2");
	return (0);
}
