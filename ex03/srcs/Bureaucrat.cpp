/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:24 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 17:25:22 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(MIN_GRADE)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int grade_, const std::string &name_) : name(name_), grade(grade_)
{
	is_grade_valid();
	std::cout << "Bureaucrat constructor called of name " << this->name << " and of grade " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other_Bureaucrat) : name(other_Bureaucrat.getName())
{
	*this = other_Bureaucrat;
	std::cout << "Copy Bureaucrat constructor called of name " << this->name << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other_Bureaucrat)
{
	grade = other_Bureaucrat.getGrade();
	is_grade_valid();
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	return (*this);
}

void	Bureaucrat::signForm(const AForm &AForm)
{
	if (grade > AForm.getGradeSign())
	{
		std::cout << name <<  " couldn’t sign " << AForm.getName() << " because " << name << "'s grade is to low." << std::endl;
		return ;
	}
	if (AForm.getIsSigned() == true)
	{
		std::cout << name <<  " couldn’t sign " << AForm.getName() << " because " << AForm.getName() << " is already signed." << std::endl;
		return ;
	}
	std::cout << name << " signed " << AForm.getName() << std::endl;
}

const std::string	&Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void	Bureaucrat::is_grade_valid()
{
	if (grade < MAX_GRADE)
		throw (GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is to high ! Grade needs to be in range 1-150!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is to low ! Grade needs to be in range 1-150!");
}

void	Bureaucrat::gradeIncrease()
{
	grade--;
	is_grade_valid();
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}
}

void	Bureaucrat::gradeDecrease()
{
	grade++;
	is_grade_valid();
}