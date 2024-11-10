/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:35:28 by eandre            #+#    #+#             */
/*   Updated: 2024/09/25 13:07:34 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm() : is_signed(false), name("Default AForm"), grade_sign(150), grade_exec(150)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const int grade_sign_, const int grade_exec_, const std::string &name_) : is_signed(false), name(name_), grade_sign(grade_sign_), grade_exec(grade_exec_)
{
	is_grade_valid();
	std::cout << "AForm constructor called of name " << this->name << " of minimum grade for sign " << grade_sign << " and of minimum grade for execute " << grade_exec << std::endl;
}

AForm::AForm(const AForm &other_AForm) : is_signed(other_AForm.is_signed), name(other_AForm.name), grade_sign(other_AForm.grade_sign), grade_exec(other_AForm.grade_exec)
{
	is_grade_valid();
	std::cout << "Copy AForm constructor called of name " << this->name << std::endl;
}

void	AForm::beSigned(const Bureaucrat &Bureaucrat)
{
	if (is_signed == true)
	{
		std::cout << "Can't sign an already signed AForm !" << std::endl;
		return ;
	}
	if (Bureaucrat.getGrade() > grade_sign)
		throw (GradeTooLowException());
	is_signed = true;
}

AForm::~AForm()
{
	std::cout << "Default AForm destructor called" << std::endl;
}

void				AForm::setIsSigned(bool set)
{
	is_signed = set;
}

AForm	&AForm::operator=(const AForm &other_AForm)
{
	is_signed = other_AForm.is_signed;
	std::cout << "AForm Copy assignment operator called" << std::endl;
	return (*this);
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is to low !");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is to high !");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed yet !");
}

const std::string	&AForm::getName() const
{
	return (name);
}

void		AForm::execute(Bureaucrat const &executor) const
{
	(void)executor;
	return ;
}

int	AForm::getGradeSign() const
{
	return (grade_sign);
}

int	AForm::getGradeExec() const
{
	return (grade_exec);
}

bool	AForm::getIsSigned() const
{
	return (is_signed);
}

void	AForm::is_grade_valid()
{
	if (grade_exec < MAX_GRADE || grade_sign < MAX_GRADE)
		throw (GradeTooHighException());
	if (grade_exec > MIN_GRADE || grade_sign > MIN_GRADE)
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	if (AForm.getIsSigned() == false)
		out << "Unsigned AForm ";
	else
		out << "Signed AForm ";
	out << AForm.getName() << ", needing grade " << AForm.getGradeSign() << " for sign "  << " and grade " << AForm.getGradeExec() << " for execute" << std::endl;
	return (out);
}