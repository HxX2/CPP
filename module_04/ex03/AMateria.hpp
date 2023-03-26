/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:20:21 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 22:26:39 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AMATERIA_HPP_
# define _AMATERIA_HPP_

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string _type;
		std::string _xp;
	public:
		AMateria();
		virtual ~AMateria();
		AMateria(const AMateria& src);
		AMateria& operator=(const AMateria& src);
		
		AMateria(const std::string& type);
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif