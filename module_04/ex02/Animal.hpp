/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:36:27 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/23 16:51:52 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef _Animal_HPP_
# define _Animal_HPP_

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal& src);
		Animal& operator=(const Animal& src);
		
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif