/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:18:09 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 23:11:00 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::~Cure()
{

}

Cure::Cure(const Cure& src)
{
	*this = src;
}

Cure& Cure::operator=(const Cure& src)
{
	(void)src;
	return *this;
}

const std::string& Cure::getType() const
{
	return this->_type;
}

Cure* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
