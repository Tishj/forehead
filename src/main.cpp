/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 21:53:16 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/25 12:28:00 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <Function.hpp>
#include <unordered_map>

#define NAME "hardhat"
//#define NAME "headsup"
//#define NAME "ahead"

//set this with -t
#define TAB_SIZE 4

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

bool	isUpToDate(Function sfunct, Function hfunct)
{
	if (sfunct.name != hfunct.name)
		return (false);
	return (true);
}

bool	isFunction(ifstream& file, string buf, Function& funct)
{
	regex	prototype("^(?:([^\\t]+)[\\ ]*)[\\t]+([^\\(]+)\\(([^\\(?\\)?]*)\\)?");
	smatch	prot_res;
	if (buf.size() <= 10 || buf[0] == '\t' || buf[0] == '/' || buf[0] == '}' || buf[0] == '{' || buf[0] == '#')
		return (false);
	if (!regex_search(buf, prot_res, prototype))
		return (false);
	funct.returnType = prot_res.str(1);
	if (!funct.returnType.compare(0, 6, "static"))
		return (false);
	funct.name = prot_res.str(2);
	if (funct.name == "main")
		return (false);
	string funct_args = prot_res.str(3);
	string remainder = prot_res.suffix().str();
	size_t	open_count = count(buf.begin(), buf.end(), '(');
	size_t	close_count = count(buf.begin(), buf.end(), ')');
	if (open_count != close_count)
	{
		while (getline(file, buf))
		{
			funct_args += buf;
			open_count += count(buf.begin(), buf.end(), '(');
			close_count += count(buf.begin(), buf.end(), ')');
			if (open_count == close_count || file.eof())
			{
				if (open_count == close_count)
					funct_args.pop_back();
				break ;
			}
		}
	}
	regex	arg("[\\t]*([^\\(\\)\\t,]+\\ +[^\\t,]+|void)(?:\\,?[\\ ]*)");
	smatch	arg_res;
	vector<string>	args;
	while (regex_search(funct_args, arg_res, arg, regex_constants::match_any))
	{
		args.push_back(arg_res.str(1));
		funct_args = arg_res.suffix().str();
	}
	funct.args = args;
	return (true);
}

void	rewriteHeader(string headerName, vector<Function> missing)
{
	ifstream	read(headerName.c_str());

	vector<string>	contents;
	string buf;
	while (getline(read, buf))
		contents.push_back(buf);
	read.close();
	if (contents.size() <= 2)
	{
		//file is considered empty
		//will handle later //TODO
		return ;
	}
	ofstream	write(headerName.c_str());
	for (size_t i = 0; i < contents.size() - 2; i++)
		write << contents[i] << endl;
	for (size_t i = 0; i < missing.size(); i++)
		write << missing[i] << ";";
	write << "\n";
	for (size_t i = contents.size() - 2; i < contents.size() ; i++)
		write << contents[i] << endl;
}

void	readFile(string name, unordered_map<string, Function>& all)
{
	ifstream			file(name.c_str());
	string				buf;
	vector<Function>	functions;

	while (getline(file, buf))
	{
		Function tmp;
		if (isFunction(file, buf, tmp))
			functions.push_back(tmp);
		if (file.eof())
			break ;
	}
	for (size_t i = 0; i < functions.size(); i++)
		all[functions[i].name] = functions[i];
}

bool	isPrototype(ifstream& file, string buf, Function& funct)
{
	regex	exp("^([^\\t]+)[\\t]+([^\\(]+)\\(([^\\)]+)");
	smatch	res;

	if (!regex_search(buf, res, exp))
		return (false);
	funct.name = res.str(2);
	funct.returnType = res.str(1);
	string remainder = res.suffix().str();
	string funct_args = res.str(3);
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
	funct.args = args;
	return (true);
}

unordered_map<string, Function>	readHeader(string headerName)
{
	unordered_map<string, Function>	prototypes;
	string buf;
	ifstream	file(headerName.c_str());

	while (getline(file, buf))
	{
		Function tmp;
		if (isPrototype(file, buf, tmp))
			prototypes[tmp.name] = tmp;
		if (file.eof())
			break ;
	}
	return (prototypes);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (error(usage()));
	unordered_map<string, Function>	functions;
	string	headerName = "";
	for (int i = 1; i < argc; i++)
	{
		if (string(argv[i]) == "-o")
		{
			if (i + 1 >= argc)
				return (error("Error: \"-o\" flag without valid file."));
			headerName = argv[i + 1];
			i++;
		}
		else
			readFile(argv[i], functions);
	}
	if (!headerName.size())
		return (error("Error: No output file specified."));
	unordered_map<string, Function>	prototypes = readHeader(headerName);
	vector<Function>	missing;
	for (auto it = functions.begin() ; it != functions.end() ; it++)
	{
		if (!isUpToDate(it->second, prototypes[it->second.name]))
			missing.push_back(it->second);
	}
	if (missing.size())
		rewriteHeader(headerName, missing);
	return (0);
}
