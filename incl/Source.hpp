/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Source.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 11:53:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/09/24 11:56:40 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_HPP
# define SOURCE_HPP

# include <iostream>
# include <string>
# include <vector>

class	Source
{
	public:
		Source();
		Source(std::string name);
		~Source();
		std::vector<std::string>	functions;
};

#endif
