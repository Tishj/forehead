/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Header.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 11:19:47 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 11:52:03 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <Header.hpp>

using namespace std;

ostream&	operator<<(ostream& stream, Header head)
{
	stream << "#ifndef " << head.guard << "\n# define " << head.guard << "\n\n";
	for (size_t i = 0; i < head.includes.size(); i++)
		stream << head.includes[i] << endl;
	stream << "\n\n";
	for (size_t i = 0; i < head.misc.size(); i++)
		stream << head.misc[i] << endl;
	stream << "\n\n";
	for (auto it = head.prototypes.begin(); it != head.prototypes.end(); it++)
		stream << it->second << endl;
	stream << "\n#endif\n\n";
	return (stream);
}
