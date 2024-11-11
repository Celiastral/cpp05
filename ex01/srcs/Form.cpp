/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:35:28 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:20:25 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"


//=== Orthodox class mandatory ===


Form::Form() : is_signed(false), name("Default Form"), grade_sign(150), grade_exec(150)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const int grade_sign_, const int grade_exec_, const std::string &name_) : is_signed(false), name(name_), grade_sign(grade_sign_), grade_exec(grade_exec_)
{
	is_grade_valid();

	std::cout << "Form constructor called of name " << this->name << " of minimum grade for sign " << grade_sign << " and of minimum grade for execute " << grade_exec << std::endl;
}

Form::Form(const Form &other_Form) : is_signed(other_Form.is_signed), name(other_Form.name), grade_sign(other_Form.grade_sign), grade_exec(other_Form.grade_exec)
{
	is_grade_valid();

	std::cout << "Copy Form constructor called of name " << this->name << std::endl;
}

Form	&Form::operator=(const Form &other_Form)
{
	is_signed = other_Form.is_signed;
	
	std::cout << "Form Copy assignment operator called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Default Form destructor called" << std::endl;
}


//=== Getter ===


const std::string	&Form::getName() const
{
	return (name);
}

int	Form::getGradeSign() const
{
	return (grade_sign);
}

int	Form::getGradeExec() const
{
	return (grade_exec);
}

bool	Form::getIsSigned() const
{
	return (is_signed);
}


//=== Grade handeling ===


void	Form::is_grade_valid()
{
	if (grade_exec < MAX_GRADE || grade_sign < MAX_GRADE)
		throw (GradeTooHighException());

	if (grade_exec > MIN_GRADE || grade_sign > MIN_GRADE)
		throw (GradeTooLowException());
}


//=== Form interaction ===


void	Form::beSigned(const Bureaucrat &Bureaucrat)
{
	if (is_signed == true)
	{
		std::cout << "\033[0;31mCan't sign an already signed Form !\033[0m"  << std::endl;
		return ;
	}

	if (Bureaucrat.getGrade() > grade_sign)
		throw (GradeTooLowException());

	is_signed = true;
}


//=== Exceptions ===


const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is to low !");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is to high !");
}


std::ostream &operator<<(std::ostream &out, Form const &Form)
{
	if (Form.getIsSigned() == false)
		out << "Unsigned Form ";
	else
		out << "Signed Form ";
	out << Form.getName() << ", needing grade " << Form.getGradeSign() << " for sign"  << " and grade " << Form.getGradeExec() << " for execute" << std::endl;
	return (out);
}