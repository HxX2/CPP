/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAPB.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:24:38 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/14 22:45:54 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
int main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "\e[0;35mWelcome to the PhoneBook!\e[0m" << std::endl;
	std::cout << "commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "\e[0;34mcmd> \e[0m";
	getline(std::cin, command);
	while (command.compare("EXIT"))
	{
		if (!command.compare("ADD"))
			phonebook.add_contact();
		else if (!command.compare("SEARCH"))
			phonebook.search_contact();
		else
			std::cout << "Invalid command" << std::endl;
		std::cout << "\e[0;34mcmd> \e[0m";
		getline(std::cin, command);
	}
	return 0;
}
