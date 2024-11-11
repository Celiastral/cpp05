/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:07:33 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 12:58:24 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:

		//=== Orthodox class mandatory ===

		Intern();
		Intern(const Intern &other_Intern);
		~Intern();

		Intern	&operator=(const Intern &other_Intern);

		//=== Form interaction ===

		AForm*	makeForm(std::string form, std::string target);

		//=== Exceptions ===

		class NotAFormException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		
};