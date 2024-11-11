/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:29 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:06:51 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		std::cout << "\033[0;32m#### CHOOSE YOUR CHARACTER ####\033[0m" << std::endl;
		try
		{
			Bureaucrat	oui(std::atoi(argv[2]), argv[1]);
			std::cout << oui;
		}
		catch (const std::exception &e)
		{
			std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
		}
	}
	else
	{
		std::cout << "\033[0;32m#### DEFAULT CHARACTER ####\033[0m" << std::endl;
		Bureaucrat	oui(10, "oui");
		std::cout << oui;
	}
	std::cout << std::endl << "\033[0;32m#### OVERFLOW GRADE ####\033[0m" << std::endl;
	try
	{
		Bureaucrat	oui(150, "Decr");
		oui.gradeDecrease();
	}
	catch(const std::exception &e)
	{
		std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl << "\033[0;32m#### UNDERFLOW GRADE ####\033[0m" << std::endl;
	try
	{
		Bureaucrat	oui(1, "Incr");
		oui.gradeIncrease();
	}
	catch(const std::exception &e)
	{
		std::cout << "\033[0;31m" << e.what() << "\033[0m" << std::endl;
	}
}