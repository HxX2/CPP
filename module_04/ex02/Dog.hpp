/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:41:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/23 03:23:43 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#ifndef _DOG_HPP_
# define _DOG_HPP_

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog();
		~Dog();
		Dog(const Dog&);
		Dog& operator=(const Dog&);

		void makeSound() const;
};

#endif