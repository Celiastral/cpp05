/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:29 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 21:51:24 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << "\033[0;32m#### CHOOSE YOUR FORM ####\033[0m" << std::endl;

		try 
		{
			Intern		PotiMonsieur;
			Bureaucrat	Big_guy(1, "Big guy");

			AForm *Form = PotiMonsieur.makeForm(argv[1], argv[2]);

			std::cout << std::endl << *Form << std::endl;
			Form->beSigned(Big_guy);
			Big_guy.executeForm(*Form);
			delete Form;
		}
		catch(const std::exception &e)
		{
			std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	else
	{
		std::cout << "\033[0;32m#### DEFAULT FORM ####\033[0m" << std::endl;
		try 
		{
			Intern	PotiMonsieur;
			AForm *Form = PotiMonsieur.makeForm("robotomy request", "PotiMonsieur");
			std::cout << std::endl << *Form << std::endl;
			delete Form;
		}
		catch(const std::exception &e)
		{
			std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}

	std::cout << std::endl << "\033[0;32m#### INTERN PRESIDENTIAL PARDON ####\033[0m" << std::endl;

	try 
	{
		Intern	PotiMonsieur;
		Bureaucrat	Big_guy(1, "Big guy");
		AForm *Form = PotiMonsieur.makeForm("presidential pardon", "PotiMonsieur");

		Form->beSigned(Big_guy);
		Big_guy.executeForm(*Form);

		delete Form;
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### INTERN ROBOTOMY REQUEST ####\033[0m" << std::endl;

	try 
	{
		Intern	PotiMonsieur;
		Bureaucrat	Big_guy(1, "Big guy");
		AForm *Form = PotiMonsieur.makeForm("robotomy request", "PotiMonsieur");

		Form->beSigned(Big_guy);
		Big_guy.executeForm(*Form);

		delete Form;
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### INTERN SHRUBBERY CREATION ####\033[0m" << std::endl;

	try 
	{
		Intern	PotiMonsieur;
		Bureaucrat	Big_guy(1, "Big guy");
		AForm *Form = PotiMonsieur.makeForm("shrubbery creation", "PotiMonsieur");

		Form->beSigned(Big_guy);
		Big_guy.executeForm(*Form);

		delete Form;
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### INTERN NO FORM ####\033[0m" << std::endl;

	try 
	{
		Intern	PotiMonsieur;
		Bureaucrat	Big_guy(1, "Big guy");
		AForm *Form = PotiMonsieur.makeForm("", "PotiMonsieur");

		Form->beSigned(Big_guy);
		Big_guy.executeForm(*Form);

		delete Form;
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}
}