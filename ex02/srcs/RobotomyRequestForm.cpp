/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:56:53 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:35:35 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"


//=== Orthodox class mandatory ===


RobotomyRequestForm::RobotomyRequestForm() : AForm(72, 45, "Default RobotomyRequestForm"), target("Nobody")
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target_) : AForm(72, 45, "RobotomyRequestForm"), target(target_)
{
	std::cout << "RobotomyRequestForm constructor called of target " << target << " of minimum grade for sign " << this->getGradeSign() << " and of minimum grade for execute " << this->getGradeExec() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other_RobotomyRequestForm) : AForm(other_RobotomyRequestForm.getGradeSign(), other_RobotomyRequestForm.getGradeExec(), other_RobotomyRequestForm.getName())
, target(other_RobotomyRequestForm.getTarget())
{
	std::cout << "Copy RobotomyRequestForm constructor called of target " << this->target << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other_RobotomyRequestForm)
{
	if (other_RobotomyRequestForm.getIsSigned())
		this->setIsSigned(true);

	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}


//=== Getter ===


const std::string	&RobotomyRequestForm::getTarget() const
{
	return (target);
}


//=== Form interaction ===


void	RobotomyRequestForm::execute(const Bureaucrat &Bureaucrat) const
{
	if (this->getIsSigned() == false)
		throw (FormNotSignedException());
	
	if (Bureaucrat.getGrade() > this->getGradeExec())
		throw (GradeTooLowException());
	
	std::cout << "* 🪚🔨DRILLING NOISES🪚🔨 *" << std::endl;
	std::cout << "* 🪚🔨DRILLING NOISES🪚🔨 *" << std::endl;
	std::cout << "* 🪚🔨DRILLING NOISES🪚🔨 *" << std::endl;
	
	if ((std::rand() % 2) + 1 == 2)
		std::cout << this->getTarget() << " has been robotomized successfully. 😊👍" << std::endl;
	else
		std::cout << this->getTarget() << " has NOT been robotomized successfully. 😔" << std::endl;
}