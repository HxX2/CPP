/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 23:06:21 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/17 18:55:06 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf((float)num * (float)(1 << this->_fractionalBits));
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = num * (1 << this->_fractionalBits);
}

Fixed& Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignation operator called" << std::endl;
	this->_fixedPointValue = src._fixedPointValue;
	return (*this);
}

bool Fixed::operator>(Fixed const &num) const
{
	if (this->_fixedPointValue > num._fixedPointValue)
		return true;
	else 
		return false;
}

bool Fixed::operator<(Fixed const &num) const
{
	if (this->_fixedPointValue < num._fixedPointValue)
		return true;
	else 
		return false;
}

bool Fixed::operator>=(Fixed const &num) const
{
	if (this->_fixedPointValue >= num._fixedPointValue)
		return true;
	else 
		return false;
}

bool Fixed::operator<=(Fixed const &num) const
{
	if (this->_fixedPointValue <= num._fixedPointValue)
		return true;
	else 
		return false;
}

bool Fixed::operator==(Fixed const &num) const
{
	if (this->_fixedPointValue == num._fixedPointValue)
		return true;
	else 
		return false;
}

bool Fixed::operator!=(Fixed const &num) const
{
	if (this->_fixedPointValue != num._fixedPointValue)
		return true;
	else 
		return false;
}

Fixed Fixed::operator-(Fixed const &num) const
{
	return (this->toFloat() - num.toFloat());
}

Fixed Fixed::operator/(Fixed const &num) const
{
	return (this->toFloat() / num.toFloat());
}

Fixed Fixed::operator*(Fixed const &num) const
{
	return (this->toFloat() * num.toFloat());
}

Fixed Fixed::operator+(Fixed const &num) const
{
	return (this->toFloat() + num.toFloat());
}

Fixed& Fixed::operator++()
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

Fixed const& Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed const& Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue / (1 << this->_fractionalBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &num)
{
	out << num.toFloat();
	return out;
}
