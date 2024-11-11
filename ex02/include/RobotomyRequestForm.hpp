/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:37:33 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:26:55 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public :
	
		//=== Orthodox class mandatory ===

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target_);
		RobotomyRequestForm(const RobotomyRequestForm &other_RobotomyRequestForm);
		~RobotomyRequestForm();

		RobotomyRequestForm			&operator=(const RobotomyRequestForm &other_RobotomyRequestForm);

		//=== Getter ===

		const std::string	&getTarget() const;

		//=== Form interaction ===

		void		execute(Bureaucrat const & executor) const;

	private :
	
		std::string	target;
};

#endif