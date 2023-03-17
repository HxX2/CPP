/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:52:41 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/17 18:54:43 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed& operator=(Fixed const &src);
		Fixed(Fixed const &src);
		~Fixed();
	
		bool operator>(Fixed const &num) const;
		bool operator<(Fixed const &num) const;
		bool operator>=(Fixed const &num) const;
		bool operator<=(Fixed const &num) const;
		bool operator==(Fixed const &num) const;
		bool operator!=(Fixed const &num) const;

		Fixed operator+(Fixed const &num) const;
		Fixed operator-(Fixed const &num) const;
		Fixed operator*(Fixed const &num) const;
		Fixed operator/(Fixed const &num) const;

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &min(Fixed &num1, Fixed &num2);
		static Fixed &max(Fixed &num1, Fixed &num2);
		static Fixed const &min(Fixed const &num1, Fixed const &num2);
		static Fixed const &max(Fixed const &num1, Fixed const &num2);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int	toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif