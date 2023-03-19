/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:08:55 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/19 15:15:37 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef _CLAPTRAP_HPP_
# define _CLAPTRAP_HPP_

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=(ClapTrap const &src);
		~ClapTrap();
	
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif