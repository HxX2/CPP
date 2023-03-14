/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:23:49 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/14 00:41:43 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	search_contact();
};

#endif