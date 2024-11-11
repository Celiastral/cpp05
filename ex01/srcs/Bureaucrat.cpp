/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:24 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:22:13 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"


//=== Orthodox class mandatory ===


Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(MIN_GRADE)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
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

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default Bureaucrat destructor called" << std::endl;
}


//=== Getter ===


const std::string	&Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}


//=== Grade handeling ===


void	Bureaucrat::gradeDecrease()
{
	grade++;
	is_grade_valid();
}

void	Bureaucrat::gradeIncrease()
{
	grade--;
	is_grade_valid();
}

void	Bureaucrat::is_grade_valid()
{
	if (grade < MAX_GRADE)
		throw (GradeTooHighException());

	if (grade > MIN_GRADE)
		throw (GradeTooLowException());
}


//=== Form interaction ===


void	Bureaucrat::signForm(const Form &Form)
{
	if (grade > Form.getGradeSign())
	{
		std::cout << "\033[0;31m" << name <<  " couldn’t sign " << Form.getName() << " because " << name << "'s grade is to low.\033[0m" << std::endl;
		return ;
	}

	if (Form.getIsSigned() == true)
	{ 
		std::cout << "\033[0;31m" << name <<  " couldn’t sign " << Form.getName() << " because " << Form.getName() << " is already signed.\033[0m" << std::endl;
		return ;
	}

	std::cout << name << " signed " << Form.getName() << std::endl;
}


//=== Exceptions ===


const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is to high ! Grade needs to be in range 1-150!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is to low ! Grade needs to be in range 1-150!");
}


std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return (out);
}