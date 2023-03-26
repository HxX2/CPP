/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:56:58 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 23:11:12 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::~Ice() 
{

}

Ice::Ice(const Ice &src)
{
	*this = src;
}

Ice &Ice::operator=(const Ice &src) 
{
	(void)src;
	return *this; 
}

const std::string &Ice::getType() const
{
	return this->_type;
}

Ice *Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
