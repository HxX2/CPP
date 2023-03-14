/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:26:42 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/14 23:26:55 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string &first_name, std::string &last_name, std::string &nick_name, std::string &darkest_secret, std::string &phone_number)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nick_name;
	this->darkest_secret = darkest_secret;
	this->phone_number = phone_number;
}

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact:: print_contact(int index, int full)
{
	std::cout << std::setw(10) << index << "|";
	if (this->first_name.length() > 10)
		std::cout << this->first_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->first_name << "|";
	if (this->last_name.length() > 10)
		std::cout << this->last_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->last_name << "|";
	if (this->nickname.length() > 10)
		std::cout << this->nickname.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->nickname << "|";
	if (full)
	{
		if (this->darkest_secret.length() > 10)
			std::cout << this->darkest_secret.substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->darkest_secret << "|";
		if (this->phone_number.length() > 10)
			std::cout << this->phone_number.substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << this->phone_number << "|";
	}
	std::cout << std::endl;
}
