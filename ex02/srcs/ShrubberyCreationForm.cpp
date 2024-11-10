/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:56:56 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 17:43:59 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(145, 137, "Default ShrubberyCreationForm"), target("Nobody")
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target_) : AForm(145, 137, "ShrubberyCreationForm"), target(target_)
{
	std::cout << "ShrubberyCreationForm constructor called of target " << target << " of minimum grade for sign " << this->getGradeSign() << " and of minimum grade for execute " << this->getGradeExec() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other_ShrubberyCreationForm) : AForm(other_ShrubberyCreationForm.getGradeSign(), other_ShrubberyCreationForm.getGradeExec(), other_ShrubberyCreationForm.getName())
, target(other_ShrubberyCreationForm.getTarget())
{
	std::cout << "Copy ShrubberyCreationForm constructor called of target " << this->target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other_ShrubberyCreationForm)
{
	if (other_ShrubberyCreationForm.getIsSigned())
		this->setIsSigned(true);
	
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &Bureaucrat) const
{
	if (this->getIsSigned() == false)
		throw (FormNotSignedException());
	if (Bureaucrat.getGrade() > this->getGradeExec())
		throw (GradeTooLowException());

	std::ofstream	outfile((this->getTarget() + "_shrubbery").c_str());
	if (!outfile || !outfile.is_open())
	{
		std::cout << "\033[0;31m" << "Error ! Outfile couldn't be created!" << "\033[0m" << std::endl;
		return ;
	}
	
	outfile <<	"		&&& &&  & &&" << std::endl;
	outfile <<	"	&& &\\/&\\|& ()|/ @, &&" << std::endl;
	outfile <<	"	&\\/(/&/&||/& /_/)_&/_&" << std::endl;
	outfile <<	"&() &\\/&|()|/&\\/ \'%\" & ()" << std::endl;
	outfile <<	"&_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	outfile <<	"&&   && & &| &| /& & % ()& /&&" << std::endl;
	outfile <<	"()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	outfile <<	"	&&     \\|||" << std::endl;
	outfile <<	"			|||" << std::endl;
	outfile <<	"			|||" << std::endl;
	outfile <<	"			|||" << std::endl;
	outfile <<	"	, -=-~  .-^- _" << std::endl;
}

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (target);
}