/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:35:25 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:11:50 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
	
		//=== Orthodox class mandatory ===
	
		Form();
		Form(const int grade_sign_, const int grade_exec_, const std::string &name_);
		Form(const Form &other_Form);
		~Form();

		Form				&operator=(const Form &other_Form);

		//=== Getter ===

		const std::string	&getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		bool				getIsSigned() const;

		//=== Form interaction ===

		void				beSigned(const Bureaucrat &Bureaucrat);

		//=== Exceptions ===

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

		bool				is_signed;
		const std::string	name;
		const int			grade_sign;
		const int			grade_exec;
		void				is_grade_valid();
};

std::ostream &operator<<(std::ostream &out, Form const &Form);

#endif