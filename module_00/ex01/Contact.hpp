/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:36:30 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/14 23:26:34 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_HPP_
# define _CONTACT_HPP_

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		std::string	phone_number;
	public:
		Contact();
		Contact(std::string &first_name, std::string &last_name, std::string &nick_name, std::string &darkest_secret, std::string &phone_number);
		~Contact();
		void print_contact(int index, int full);
};

#endif