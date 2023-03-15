/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:45:24 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 15:20:10 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WEAPON_HPP_
# define _WEAPON_HPP_

# include <iostream>
# include <string>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon( std::string type);
		~Weapon();
		void setType( std::string type );
		std::string getType( void );
};

#endif