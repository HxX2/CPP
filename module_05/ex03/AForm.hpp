#ifndef _AFORM_HPP_
#define _AFORM_HPP_

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _grade_to_sign;
	const int _grade_to_execute;
	bool _signed;
	std::string _target;

public:
	AForm();
	AForm(std::string name, int grade_to_sign, int grade_to_execute);
	virtual ~AForm();
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getTarget() const;
	void setTarget(std::string target);
	void beSigned(Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;
	virtual void action() const = 0;

	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif