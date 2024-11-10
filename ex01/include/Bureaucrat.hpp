/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:05:33 by eandre            #+#    #+#             */
/*   Updated: 2024/11/07 14:53:58 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Form;

class Bureaucrat
{
	public :

		Bureaucrat();
		Bureaucrat(int grade_, const std::string &name_);
		Bureaucrat(const Bureaucrat &other_Bureaucrat);
		~Bureaucrat();

		Bureaucrat			&operator=(const Bureaucrat &other_Bureaucrat);

		const std::string	&getName() const;
		int					getGrade() const;

		void				gradeIncrease();
		void				gradeDecrease();

		void				signForm(const Form &Form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private :

		void				is_grade_valid();
		const std::string	name;
		int					grade;
		
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif