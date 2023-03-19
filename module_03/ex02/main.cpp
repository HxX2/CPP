/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:55:55 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/19 15:50:12 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap scav("farid");
	FragTrap frag("karim");

	scav.attack("karim");
	frag.takeDamage(20);
	frag.beRepaired(15);
	frag.highFivesGuys();
	scav.guardGate();
	
	return 0;
}