/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:13:31 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/19 15:30:18 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->_name = "def";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &srs)
{
	std::cout << "ScavTrap copy assignation operator called" << std::endl;
	if (this != &srs)
	{
		this->_name = srs._name;
		this->_hitPoints = srs._hitPoints;
		this->_energyPoints = srs._energyPoints;
		this->_attackDamage = srs._attackDamage;
	}
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " has activated Gate keeper mode." << std::endl;
}
