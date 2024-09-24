/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:29 by eandre            #+#    #+#             */
/*   Updated: 2024/09/24 10:22:53 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		try
		{
			Bureaucrat	oui(std::atoi(argv[2]), argv[1]);
			std::cout << oui;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		Bureaucrat	oui(10, "oui");
		std::cout << oui;
	}
	try
	{
		Bureaucrat	oui(150, "Decr");
		oui.gradeDecrease();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	oui(1, "Incr");
		oui.gradeIncrease();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}