/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:29:02 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/17 22:13:03 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("def"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "ClapTrap copy assignation operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy to attack!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead!" << std::endl;
		return ;
	}
	std::cout << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy to be repaired!" << std::endl;
		return ;
	}
	this->_energyPoints -= 1;
	this->_hitPoints += amount;
	std::cout << this->_name << " is repaired by " << amount << " points!" << std::endl;
}
