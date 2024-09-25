/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:29 by eandre            #+#    #+#             */
/*   Updated: 2024/09/25 13:10:22 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc > 3)
	{
		std::cout << "\033[0;32m#### CHOOSE YOUR CHARACTER ####\033[0m" << std::endl;
		try
		{
			Form	form(std::atoi(argv[1]), std::atoi(argv[2]), argv[3]);
			std::cout << form;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "\033[0;32m#### DEFAULT CHARACTER ####\033[0m" << std::endl;
		Form	form(150, 150, "yipee i'm a Form");
		std::cout << form;
	}
	std::cout << std::endl << "\033[0;32m#### OVERFLOW SIGN ####\033[0m" << std::endl;
	try
	{
		Form	form(160, 150, "yipee i'm a Form");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[0;32m#### OVERFLOW EXEC ####\033[0m" << std::endl;
	try
	{
		Form	form(150, 160, "yipee i'm a Form");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[0;32m#### UNDERFLOW SIGN ####\033[0m" << std::endl;
	try
	{
		Form	form(-1, 150, "yipee i'm a Form");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[0;32m#### UNDERFLOW EXEC ####\033[0m" << std::endl;
	try
	{
		Form	form(1, -150, "yipee i'm a Form");
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "\033[0;32m#### FORM SIGN ALREADY SIGNED ####\033[0m" << std::endl;
	Form		form(1, 150, "yipee i'm a Form");
	Bureaucrat	Bur(1, "oui");

	Bur.signForm(form);
	form.beSigned(Bur);
	Bur.signForm(form);
	form.beSigned(Bur);

	std::cout << std::endl << "\033[0;32m#### FORM SIGN UNDERGRADED ####\033[0m" << std::endl;
	try
	{
		Form		form_(1, 150, "yipee i'm a Form");
		Bureaucrat	Bur_(150, "oui");

		Bur_.signForm(form_);
		form_.beSigned(Bur_);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}