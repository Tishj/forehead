/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Source.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 11:56:59 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 12:20:22 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <Source.hpp>
#include <fstream>

using namespace std;

Source::Source() {} ;

Source::~Source() {} ;

bool	isFunction(ifstream file, string buf, Function& funct)
{
//	regex	expr("^(.*)[\\t]*(.*)\\(.*")

}

Source::Source(string name)
{
	ifstream	file(name.c_str());
	

}
