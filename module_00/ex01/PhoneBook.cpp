/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:47:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/14 23:30:52 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::search_contact()
{	
	std::string	index;
	int i;

	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	std::cout << "----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < this->index && i < 8; i++)
	{
		this->contacts[i].print_contact(i + 1, false);
	}
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "\e[0;33mIndex: \e[0m";
	getline(std::cin, index);
	i = std::atoi(index.c_str());
	if (i > 0 && i <= this->index && i <= 8)
	{
		std::cout << "------------------------------------------------------------------" << std::endl;
		std::cout << "     index|first name| last name|  nickname|  dark sec| phone num|" << std::endl;
		std::cout << "----------+----------+----------+----------+----------+----------+" << std::endl;
		this->contacts[i-1].print_contact(i, true);
		std::cout << "------------------------------------------------------------------" << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void PhoneBook::add_contact()
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string darkest_secret;
	std::string phone_number;

	std::cout << "First name: ";
	getline(std::cin, first_name);
	std::cout << "Last name: ";
	getline(std::cin, last_name);
	std::cout << "Nickname: ";
	getline(std::cin, nick_name);
	std::cout << "Dark secret: ";
	getline(std::cin, darkest_secret);
	std::cout << "Phone number: ";
	getline(std::cin, phone_number);
	
	this->contacts[this->index % 8] = Contact(first_name, last_name, nick_name, darkest_secret, phone_number);
	this->index++;
}