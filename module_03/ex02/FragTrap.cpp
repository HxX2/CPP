/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 15:36:32 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/19 15:51:24 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_name = "def";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap& FragTrap::operator=(FragTrap const &srs)
{
	std::cout << "FragTrap copy assignation operator called" << std::endl;
	if (this != &srs)
	{
		this->_name = srs._name;
		this->_hitPoints = srs._hitPoints;
		this->_energyPoints = srs._energyPoints;
		this->_attackDamage = srs._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " has requested High Fives." << std::endl;
}
