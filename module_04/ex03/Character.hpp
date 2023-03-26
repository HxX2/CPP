/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:47:10 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/25 21:51:39 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _CHARACTER_HPP_
# define _CHARACTER_HPP_

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria* _enventory[4];
		std::string _name;
	public:
		Character();
		~Character();
		Character(const Character& src);
		Character& operator=(const Character& src);
		
		Character(const std::string& name);
		const std::string& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif