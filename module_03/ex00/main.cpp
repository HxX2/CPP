/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:55:55 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/17 22:16:49 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap saitama("saitama");
	ClapTrap hamid("hamid");

	hamid.attack("saitama");
	saitama.takeDamage(1);
	saitama.beRepaired(1);
	saitama.attack("hamid");
	hamid.takeDamage(10);
	return (0);
}