/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:42:38 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/23 03:23:25 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() 
{
	type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat& src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
		this->type = src.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "miaw miaw" << std::endl;
}