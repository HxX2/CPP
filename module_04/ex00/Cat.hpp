/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:40:15 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/23 02:22:18 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef _Cat_HPP_
# define _Cat_HPP_

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat&);
		Cat& operator=(const Cat&);

		void makeSound() const;
};

#endif