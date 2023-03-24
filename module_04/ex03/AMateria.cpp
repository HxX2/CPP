/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:29:05 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/23 19:35:04 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria& AMateria::operator=(const AMateria& src)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return *this;
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	
}

const std::string& AMateria::getType() const
{
	return this->_type;
}
