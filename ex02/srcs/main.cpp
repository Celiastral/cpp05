/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:29 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 17:43:04 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << "\033[0;32m#### CHOOSE YOUR FORM ####\033[0m" << std::endl;

		switch (std::atoi(argv[1]))
		{
			case 0:
			{
				PresidentialPardonForm	PPForm(argv[2]);

				std::cout << std::endl << PPForm << std::endl;
				break ;
			}
			case 1:
			{
				RobotomyRequestForm		RRForm(argv[2]);

				std::cout << std::endl << RRForm << std::endl;
				break ;
			}
			case 2:
			{
				ShrubberyCreationForm	SCForm(argv[2]);

				std::cout << std::endl << SCForm << std::endl;
				break ;
			}
			default:
			{
				std::cout << "Please enter a number between 0 and 2!" << std::endl;
				return (1);
			}
		}
	}
	else
	{
		std::cout << "\033[0;32m#### DEFAULT FORM ####\033[0m" << std::endl;

		RobotomyRequestForm	form("Little guy");

		std::cout << std::endl << form << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### UNDERGRADE ROBOTOMY REQUEST SIGN ####\033[0m" << std::endl;

	try
	{
		RobotomyRequestForm	form("Little guy");
		Bureaucrat			Big_guy(150, "Big guy");

		form.beSigned(Big_guy);
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### UNDERGRADE PRESIDENTIAL PARDON SIGN ####\033[0m" << std::endl;
	
	try
	{
		PresidentialPardonForm	form("Little guy");
		Bureaucrat				Big_guy(150, "Big guy");

		form.beSigned(Big_guy);
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### UNDERGRADE SHRUBBERY CREATION SIGN ####\033[0m" << std::endl;
	
	try
	{
		ShrubberyCreationForm	form("Little guy");
		Bureaucrat				Big_guy(150, "Big guy");

		form.beSigned(Big_guy);
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}
	
	std::cout << std::endl << "\033[0;32m#### UNSIGNED ROBOTOMY REQUEST EXECFORM ####\033[0m" << std::endl;

	RobotomyRequestForm	RRform("Little guy");
	Bureaucrat				Big_guy(150, "Big guy");

	Big_guy.executeForm(RRform);

	std::cout << std::endl << "\033[0;32m#### UNSIGNED SHRUBBERY CREATION EXECFORM ####\033[0m" << std::endl;

	ShrubberyCreationForm	SCform("Little guy");

	Big_guy.executeForm(SCform);

	std::cout << std::endl << "\033[0;32m#### UNSIGNED PRESIDENTIAL PARDON EXECFORM ####\033[0m" << std::endl;

	PresidentialPardonForm	PPform("Little guy");

	Big_guy.executeForm(PPform);

	std::cout << std::endl << "\033[0;32m#### UNDERGRADE ROBOTOMY REQUEST EXEC ####\033[0m" << std::endl;
	try
	{
		RobotomyRequestForm		RRform("Little guy");
		Bureaucrat				Big_guy(72, "Big guy");

		RRform.beSigned(Big_guy);
		RRform.execute(Big_guy);
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### UNDERGRADE PRESIDENTIAL PARDON EXEC ####\033[0m" << std::endl;
	try
	{
		PresidentialPardonForm	PPform("Little guy");
		Bureaucrat				Big_guy(25, "Big guy");

		PPform.beSigned(Big_guy);
		PPform.execute(Big_guy);
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### UNDERGRADE SHRUBBERY CREATION EXEC ####\033[0m" << std::endl;
	try
	{
		ShrubberyCreationForm	SCform("Little guy");
		Bureaucrat				Big_guy(145, "Big guy");

		SCform.beSigned(Big_guy);
		SCform.execute(Big_guy);
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### CAN'T OPEN SHRUBBERY CREATION EXEC ####\033[0m" << std::endl;
	try
	{
		ShrubberyCreationForm	SCform("/*&daz");
		Bureaucrat				Big_guy(1, "Big guy");

		SCform.beSigned(Big_guy);
		SCform.execute(Big_guy);
	}
	catch(const std::exception &e)
	{
		std::cerr << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << std::endl << "\033[0;32m#### NO ERROR ROBOTOMY REQUEST EXEC ####\033[0m" << std::endl;

	Bureaucrat				Bigger_guy(1, "Big guy");

	RRform.beSigned(Bigger_guy);
	RRform.execute(Bigger_guy);

	std::cout << std::endl << "\033[0;32m#### NO ERROR PRESIDENTIAL PARDON EXEC ####\033[0m" << std::endl;

	PPform.beSigned(Bigger_guy);
	PPform.execute(Bigger_guy);

	std::cout << std::endl << "\033[0;32m#### NO ERROR SHRUBBERY CREATION EXEC ####\033[0m" << std::endl << std::endl;

	SCform.beSigned(Bigger_guy);
	SCform.execute(Bigger_guy);
}