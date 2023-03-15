/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:23:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 20:13:37 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("debug");
	std::cout << "[ INFO ]" << std::endl;
	harl.complain("info");
	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("warning");
	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("error");

	return 0;
}