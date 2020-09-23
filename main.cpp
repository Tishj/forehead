/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 21:53:16 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 00:52:44 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define NAME "hardhat"
//#define NAME "headsup"

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

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (error(usage()));
	return (0);
}
