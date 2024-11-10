/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:35:25 by eandre            #+#    #+#             */
/*   Updated: 2024/09/24 22:57:30 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public :

		AForm();
		AForm(const int grade_sign_, const int grade_exec_, const std::string &name_);
		AForm(const AForm &other_AForm);
		virtual ~AForm();
	
		AForm				&operator=(const AForm &other_AForm);
	
		const std::string	&getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		bool				getIsSigned() const;

		virtual void		execute(Bureaucrat const & executor) const  = 0;
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

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

	protected :

		void				setIsSigned(bool set);

	private :

		bool				is_signed;
		const std::string	name;
		const int			grade_sign;
		const int			grade_exec;
		void				is_grade_valid();
	
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);

#endif