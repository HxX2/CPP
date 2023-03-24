/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:41:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/23 02:22:47 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef _DOG_HPP_
# define _DOG_HPP_

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);

		void makeSound() const;
};

#endif