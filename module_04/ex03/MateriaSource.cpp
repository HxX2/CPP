/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:26:02 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/26 23:12:31 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0)
{

}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _idx; i++)
		delete _materia[i];
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < _idx; i++)
			delete _materia[i];
		_idx = src._idx;
		for (int i = 0; i < _idx; i++)
			_materia[i] = src._materia[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (_idx >= 4)
		return ;
	AMateria* tmp = m->clone();
	_materia[_idx] = tmp;
	_idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < _idx; i++)
	{
		if (_materia[i]->getType() == type)
			return _materia[i]->clone();
	}
	return NULL;
}
