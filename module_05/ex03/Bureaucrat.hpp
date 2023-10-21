/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:06:40 by zlafou            #+#    #+#             */
/*   Updated: 2023/10/21 17:32:54 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BUREAUCRAT_HPP_
#define _BUREAUCRAT_HPP_

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);

	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &f);
	void executeForm(AForm const &form);

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif