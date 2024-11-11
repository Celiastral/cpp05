/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:05:33 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:09:53 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
	public :

		//=== Orthodox class mandatory ===
		
		Bureaucrat();
		Bureaucrat(int grade_, const std::string &name_);
		Bureaucrat(const Bureaucrat &other_Bureaucrat);
		~Bureaucrat();

		Bureaucrat			&operator=(const Bureaucrat &other_Bureaucrat);

		//=== Getter ===

		const std::string	&getName() const;
		int					getGrade() const;

		//=== Grade modification ===

		void				gradeIncrease();
		void				gradeDecrease();

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

		const std::string	name;
		int					grade;
		void				is_grade_valid();
	
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif