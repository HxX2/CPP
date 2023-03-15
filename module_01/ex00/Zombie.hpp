/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 00:23:57 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 01:18:38 by zlafou           ###   ########.fr       */
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
		void announce(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif