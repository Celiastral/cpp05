/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:07:37 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 13:39:05 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"


//=== Orthodox class mandatory ===


Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other_Intern)
{
	(void)other_Intern;

	std::cout << "Copy Intern constructor called" << std::endl;
}

Intern	&Intern::operator=(const Intern &other_Intern)
{
	(void)other_Intern;

	std::cout << "Intern Copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Default Intern destructor called" << std::endl;
}


//=== Form interaction ===


AForm	*Intern::makeForm(std::string form, std::string target)
{
	int	i;
	
	std::string	Form_type[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	i = 0;
	while (i < 4)
	{
		if (Form_type[i] == form)
			break ;
		i++;
	}
	
	switch (i)
	{
		case 0:
			std::cout << "Intern creates Shubbery Creation" << std::endl;
			return (new ShrubberyCreationForm(target));
			
		case 1:
			std::cout << "Intern creates Robotomy Request" << std::endl;
			return (new RobotomyRequestForm(target));

		case 2:
			std::cout << "Intern creates Presidential Pardon" << std::endl;
			return (new PresidentialPardonForm(target));
			
		default :
			throw(NotAFormException());
			break;
	}
}


//=== Exceptions ===


const char	*Intern::NotAFormException::what() const throw()
{
	return ("This is not a normal form! Try using \"shrubbery creation\", \"robotomy request\" or \"presidential pardon\"!");
}