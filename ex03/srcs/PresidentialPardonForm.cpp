/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:56:51 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 16:50:29 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(25, 5, "Default PresidentialPardonForm"), target("Nobody")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target_) : AForm(25, 5, "PresidentialPardonForm"), target(target_)
{
	std::cout << "PresidentialPardonForm constructor called of target " << target << " of minimum grade for sign " << this->getGradeSign() << " and of minimum grade for execute " << this->getGradeExec() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other_PresidentialPardonForm) : AForm(other_PresidentialPardonForm.getGradeSign(), other_PresidentialPardonForm.getGradeExec(), other_PresidentialPardonForm.getName())
, target(other_PresidentialPardonForm.getTarget())
{
	std::cout << "Copy PresidentialPardonForm constructor called of target " << this->target << std::endl;
}

void	PresidentialPardonForm::execute(const Bureaucrat &Bureaucrat) const
{
	if (this->getIsSigned() == false)
		throw (FormNotSignedException());
	if (Bureaucrat.getGrade() > this->getGradeExec())
		throw (GradeTooLowException());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other_PresidentialPardonForm)
{

	if (other_PresidentialPardonForm.getIsSigned())
		this->setIsSigned(true);

	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string	&PresidentialPardonForm::getTarget() const
{
	return (target);
}