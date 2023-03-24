/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:41:22 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/23 03:23:48 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
	type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog& src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}
