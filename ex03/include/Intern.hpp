/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:07:33 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 21:31:47 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
	public:

		Intern();
		Intern(const Intern &other_Intern);
		~Intern();

		Intern	&operator=(const Intern &other_Intern);

		AForm*	makeForm(std::string form, std::string target);

		class NotAFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
};