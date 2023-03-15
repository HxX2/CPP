/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 03:03:30 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 15:21:16 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type)
{

}

Weapon::Weapon()
{

}

Weapon::~Weapon()
{

}

void Weapon::setType( std::string type )
{
	this->type = type;
}

std::string Weapon::getType( void )
{
	return this->type;
}