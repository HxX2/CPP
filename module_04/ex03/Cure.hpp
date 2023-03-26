/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:43:45 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 22:34:15 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CURE_HPP_
# define _CURE_HPP_

# include "AMateria.hpp"
# include "ICharacter.hpp"
class Cure : public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& src);
		Cure& operator=(const Cure& src);
		
		const std::string& getType() const;
		Cure* clone() const;
		void use(ICharacter& target);
};

#endif