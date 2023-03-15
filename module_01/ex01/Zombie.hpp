/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:23:57 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 02:20:38 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP_
# define _ZOMBIE_HPP_

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie( std::string name );
		Zombie();
		~Zombie();
		void setName( std::string name );
		void announce(void);
};

Zombie* zombieHorde( int N, std::string name );


#endif