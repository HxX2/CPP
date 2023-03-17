/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:52:41 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 23:04:05 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _FIXED_HPP_
# define _FIXED_HPP_

#include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed &operator=(Fixed const &src);
		~Fixed();
	
		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif