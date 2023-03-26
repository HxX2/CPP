/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:29:05 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 23:10:10 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{

}

AMateria::~AMateria()
{

}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

AMateria::AMateria(const std::string &type) : _type(type)
{
}

const std::string &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use called on " << target.getName() << std::endl;
}
