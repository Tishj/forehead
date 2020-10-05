/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Function.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 15:49:30 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 13:40:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <Function.hpp>
#include <HeaderData.hpp>

using namespace std;

Function::Function() : HeaderData(PROTOTYPE) {}

Function::Function(string ret, string name, vector<string> args) : HeaderData(PROTOTYPE), returnType(ret), name(name), args(args) {}

Function::Function(const Function& funct) : HeaderData(PROTOTYPE), returnType(funct.returnType), name(funct.name), args(funct.args)
{
	this->args = funct.args;
	this->name = funct.name;
	this->returnType = funct.returnType;
	this->raw = funct.raw;
}

Function::~Function() {};
