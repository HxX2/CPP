#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _grade_to_sign;
	const int _grade_to_execute;
	bool _signed;

public:
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	~Form();
	Form(const Form &src);
	Form &operator=(const Form &src);

	std::string getName() const;

	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif