/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HeaderData.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 16:14:20 by tbruinem      #+#    #+#                 */
/*   Updated: 2020/10/02 17:54:40 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_DATA_HPP
# define HEADER_DATA_HPP

# include <string>

enum	e_headerdata
{
	OBJECT,
	TYPEDEF,
	MISC,
	PROTOTYPE,
	OTHER,
	HEAD,
	GUARD,
	INCLUDE,
	DEFINE,
	COMMENT
};

class HeaderData
{
	private:
		e_headerdata type;
	public:
		std::string raw;
		e_headerdata	getType(void) {return (this->type); }
		HeaderData(e_headerdata type) : type(type) {}
		virtual std::string print(size_t indent) const = 0;
		virtual ~HeaderData() {}
};

#endif
