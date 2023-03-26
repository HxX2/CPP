/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:47:12 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 22:34:09 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ICE_HPP_
# define _ICE_HPP_

# include "AMateria.hpp"
# include "ICharacter.hpp"
class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& src);
		Ice& operator=(const Ice& src);
		
		const std::string& getType() const;
		Ice* clone() const;
		void use(ICharacter& target);
};

#endif