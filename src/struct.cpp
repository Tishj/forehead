/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 14:46:39 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/25 16:13:06 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <Struct.hpp>

using namespace std;

bool	isStruct(ifstream& file, string buf, vector<Struct>& all)
{
	Struct	newStruct;
	
	if (buf.size() <= 7 || (buf.compare(0, 6, "struct") && buf.compare(0, 7, "typedef")) || buf[buf.size() - 1] == ';')
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
	all.push_back(newStruct);
	return (true);
}

void	readFile(string fileName, vector<Struct>& all)
{
	ifstream	file(fileName.c_str());

	string buf;
	while (getline(file, buf))
	{
		if (!isStruct(file, buf, all))

		if (file.eof())
			break ;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	string file = argv[1];
	vector<Struct>	structs;

	readFile(file, structs);
	for (size_t i = 0; i < structs.size() ; i++)
	{
		if (structs[i].tdef.size())
			cout << "typedef struct" << '\t' << structs[i].name << "\n{\n";
		else
			cout << "struct" << '\t' << structs[i].name << "\n{\n";
		for (size_t j = 0; j < structs[i].elements.size() ; j++)
			cout << "\t" << structs[i].elements[j].first << "\t" << structs[i].elements[j].second << "\n";
		cout << "}";
		if (structs[i].tdef.size())
			cout << "\t" << structs[i].tdef;
		cout << "\n";
	}
	return (0);
}
