/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 01:16:29 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 02:07:12 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
	{
		zombie[i].announce();
	}
	delete [] zombie;
	return 0;
}