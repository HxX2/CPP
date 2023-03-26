/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:26:49 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 23:13:38 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_enventory[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->_enventory[i];
}

Character::Character(const Character& src)
{
	for (int i = 0; i < 4; i++)
		this->_enventory[i] = NULL;
	*this = src;
}

Character& Character::operator=(const Character& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
			delete this->_enventory[i];
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (src._enventory[i] != NULL)
				this->_enventory[i] = src._enventory[i]->clone();
			else
				this->_enventory[i] = NULL;
		}
	}
	return *this;
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_enventory[i] = NULL;
}

const std::string& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_enventory[i] == NULL)
		{
			this->_enventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		delete this->_enventory[idx];
		this->_enventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_enventory[idx] != NULL)
			this->_enventory[idx]->use(target);
	}
}
