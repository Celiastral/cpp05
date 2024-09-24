/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:35:25 by eandre            #+#    #+#             */
/*   Updated: 2024/09/24 22:57:30 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
		Form();
		Form(const int grade_sign_, const int grade_exec_, const std::string &name_);
		Form(const Form &other_Form);
		~Form();
		Form				&operator=(const Form &other_Form);
		const std::string	&getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		bool				getIsSigned() const;
		void				beSigned(const Bureaucrat &Bureaucrat);
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
		bool				is_signed;
		const std::string	name;
		const int			grade_sign;
		const int			grade_exec;
};

std::ostream &operator<<(std::ostream &out, Form const &Form);

#endif