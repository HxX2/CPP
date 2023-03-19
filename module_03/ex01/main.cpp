/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:55:55 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/19 15:32:29 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("farid");

	scav.attack("hamid");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	return 0;
}