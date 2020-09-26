/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 21:53:16 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/26 18:04:48 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <Function.hpp>
#include <unordered_map>
#include <unistd.h>
#include <sys/stat.h>
#include <Struct.hpp>
#include <Header.hpp>
#include <Other.hpp>

//#define NAME "hardhat"
#define NAME "forehead"
//#define NAME "headsup"
//#define NAME "ahead"

#define TAB_SIZE 4

using namespace std;

string	usage()
{
	string out;

	out += "Usage: forehead [OPTION]... [input-files]...";
	return (out);
}

int	error(string errmsg)
{
	cerr << errmsg << endl;
	return (1);
}

bool exists (const std::string& name)
{
	return ( access( name.c_str(), F_OK ) != -1 );
}

bool	isUpToDate(Function sfunct, Function hfunct)
{
	if (sfunct.name != hfunct.name)
		return (false);
	return (true);
}

vector<string>	splitArgs(string list)
{
	size_t	idx = 0;
	size_t	next;
	string withoutTabs;
	for (size_t index = 0; index < list.size() ; index++)
		if (list[index] != '\t')
			withoutTabs += list[index];
	list = withoutTabs;
	vector<string>	args;
	for (; idx < list.size(); idx = next)
	{
		next = list.find(',', idx + 1);
		if (next == string::npos)
			next = list.size() + 1;
		string raw = list.substr(idx != 0 ? idx + 1: idx, idx ? next - 1 - idx : next - idx);
		size_t start = (raw[0] == ' ') ? raw.find_first_not_of(' ') : 0;
		size_t end = (raw[raw.size() - 1] == ' ') ? raw.find_last_not_of(' ') : raw.size();
		raw = raw.substr(start, end - start);
		args.push_back(raw);
	}
	return (args);
}

bool	isFunction(ifstream& file, string buf, Function& funct)
{
	regex	prototype("^(?:([^\\t]+)[\\ ]*)[\\t]+([^\\(]+)([\\[\\]\\.0-9a-z_\\* ,\\(\\)]+)");
	smatch	prot_res;
	if (buf.size() <= 10 || buf[0] == '\t' || buf[0] == '/' || buf[0] == '}' || buf[0] == '{' || buf[0] == '#' || buf[0] == '*')
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
				break ;
		}
	}
	funct_args = funct_args.substr(1, funct_args.size() - 2);
	funct.args = splitArgs(funct_args);
	return (true);
}

void	rewriteHeader(string headerName, Header& header)
{
	ofstream	write(headerName.c_str());

	bool	acceptNewLine = true;
	size_t	endOfMisc = (header.misc.size()) ? header.misc.size() - 1 : header.misc.size();
	for (size_t i = 0; i < endOfMisc ; i++)
	{
		if (header.misc[i].empty())
		{
			if (acceptNewLine)
			{
				write << endl;
				acceptNewLine = false;
			}
		}
		else if (header.misc.size() > 1)
		{
			acceptNewLine = true;
			write << header.misc[i] << endl;
		}
	}
	for (size_t i = 0; i < header.others.size() ; i++)
		write << header.others[i].print(6) << endl;
	write << endl;
	for (size_t i = 0; i < header.enums.size() ; i++)
		write << header.enums[i].print(6) << endl;
	for (size_t i = 0; i < header.structs.size() ; i++)
		write << header.structs[i].print(6) << endl;
	for (auto it = header.prototypes.begin(); it != header.prototypes.end() ; it++)
		write << it->second.print(6) << endl;
	write << "\n#endif\n";
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
	regex	exp("^([^\\t]+)[\\t]+([^\\(]+)([\\[\\]\\.0-9a-z_\\* ,\\(??\\)??;]+)");
	smatch	res;

	if (buf.size() <= 3 || buf[0] == '*' || buf[0] == '/')
		return (false);
	if (!regex_search(buf, res, exp))
		return (false);
	funct.name = res.str(2);
	funct.returnType = res.str(1);
	string funct_args = res.str(3);
	if (funct_args.size() <= 3)
		return (false);
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
				break ;
		}
	}
	funct_args = funct_args.substr(1, funct_args.size() - 3);
	funct.args = splitArgs(funct_args);
	return (true);
}

bool	isOther(string buf, Other& newOther)
{
	if (buf.size() <= 4 || buf[0] == '\t' || buf[0] == '}' || buf[0] == '{' || buf[0] == '*' || buf[buf.size() - 1] != ';' || !count(buf.begin(), buf.end(), '\t') || count(buf.begin(), buf.end(), '('))
		return (false);
	size_t	idx = 0;
	for (; idx < buf.size() && buf[idx] != '\t'; idx++)
		newOther.type += buf[idx];
	for (; idx < buf.size() && buf[idx] == '\t'; idx++) {}
	for (; idx < buf.size() && buf[idx] != '\t'; idx++)
		newOther.name += buf[idx];
	return (true);
}

bool	isEnum(ifstream& file, string buf, Enum& newEnum)
{
	if (buf.size() <= 7 || buf[0] == '*' || (buf.compare(0, 4, "enum") && buf.compare(0, 12, "typedef enum") && buf.compare(0, 12, "typedef\tenum")) || buf[buf.size() - 1] == ';')
		return (false);
	size_t	lastTab = buf.rfind('\t');
	if (lastTab == string::npos)
		return (false);
	newEnum.name = buf.substr(lastTab + 1, (buf.size() - lastTab - 1));
	getline(file, buf);
	while (getline(file, buf))
	{
		size_t	closeBracket = buf.find('}');
		if (closeBracket != string::npos)
		{
			lastTab = buf.rfind('\t');
			if (lastTab != string::npos)
				newEnum.tdef = buf.substr(lastTab + 1, buf.size() - lastTab - 1);
		}
		else
		{
			size_t idx = 0;
			for (; idx < buf.size() && buf[idx] == '\t';idx++) {}
			newEnum.elements.push_back(buf.substr(idx, buf.size() - idx));
		}
		if (file.eof() || closeBracket != string::npos)
			break ;
	}
	return (true);
}

bool	isStruct(ifstream& file, string buf, Struct& newStruct)
{
	if (buf.size() <= 7 || buf[0] == '*' || (buf.compare(0, 6, "struct") && buf.compare(0, 14, "typedef struct") && buf.compare(0, 14, "typedef\tstruct")) || buf[buf.size() - 1] == ';')
		return (false);
	size_t	lastTab = buf.rfind('\t');
	if (lastTab == string::npos)
		return (false);
	newStruct.name = buf.substr(lastTab + 1, (buf.size() - lastTab - 1));
	getline(file, buf);
	while (getline(file, buf))
	{
		size_t	closeBracket = buf.find('}');
		if (closeBracket != string::npos)
		{
			lastTab = buf.rfind('\t');
			if (lastTab != string::npos)
				newStruct.tdef = buf.substr(lastTab + 1, buf.size() - lastTab - 1);
		}
		else
		{
			string name;
			string type;
			size_t idx = 0;
			for (; idx < buf.size() && buf[idx] == '\t';idx++) {}
			for (; idx < buf.size() && buf[idx] != '\t';idx++)
				type += buf[idx];
			for (; idx < buf.size() && buf[idx] == '\t';idx++) {}
			for (; idx < buf.size() && buf[idx] != '\t';idx++)
				name += buf[idx];
			newStruct.elements.push_back(pair<string, string>(type, name));
		}
		if (file.eof() || closeBracket != string::npos)
			break ;
	}
	return (true);
}

void	readHeader(string headerName, Header& header)
{
	string buf;
	ifstream	file(headerName.c_str());

	while (getline(file, buf))
	{
		Struct newStruct;
		Enum newEnum;
		Function newFunct;
		Other newOther;
		if (isPrototype(file, buf, newFunct))
			header.prototypes[newFunct.name] = newFunct;
		else if (isOther(buf, newOther))
			header.others.push_back(newOther);
		else if (isStruct(file, buf, newStruct))
			header.structs.push_back(newStruct);
		else if (isEnum(file, buf, newEnum))
			header.enums.push_back(newEnum);
		else
			header.misc.push_back(buf);
		if (file.eof())
			break ;
	}
}

string	createGuard(string headerName)
{
	string guard;

	for (size_t i = 0; i < headerName.size(); i++)
	{
		if (isalpha(headerName[i]) && islower(headerName[i]))
			guard += toupper(headerName[i]);
		else
		{
			if (i && islower(headerName[i - 1]))
				guard += "_";
			if (isalpha(headerName[i]))
				guard += headerName[i];
		}
	}
	return (guard);
}

void	createHeader(string headerName, Header& headerData)
{
	ofstream	header(headerName.c_str());

	size_t	path_separator = headerName.find_last_of('/');
	if (path_separator != string::npos)
		headerName = headerName.substr(path_separator + 1, headerName.size());
	string guard = createGuard(headerName);
	header << "#ifndef " << guard << "\n# define " << guard << "\n\n";
	for (auto it = headerData.prototypes.begin(); it != headerData.prototypes.end() ; it++)
		header << it->second.print(6) << endl;
	header << "\n#endif\n";
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (error(usage()));
	unordered_map<string, Function>	functions;
	string	headerName = "";
	Header	headerData;
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
	readHeader(headerName, headerData);
	int	newPrototypes = 0;
	for (auto it = functions.begin() ; it != functions.end() ; it++)
	{
		if (!isUpToDate(it->second, headerData.prototypes[it->second.name]))
		{
			headerData.prototypes[it->second.name] = it->second;
			newPrototypes++;
		}
	}
	if (newPrototypes)
	{
		if (exists(headerName))
			rewriteHeader(headerName, headerData);
		else
			createHeader(headerName, headerData);
	}
	return (0);
}
