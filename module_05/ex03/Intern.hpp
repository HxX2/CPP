#ifndef _INTERN_HPP_
#define _INTERN_HPP_

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &src);
	Intern &operator=(const Intern &src);

	AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif