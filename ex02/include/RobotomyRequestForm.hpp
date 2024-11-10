/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:37:33 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 15:38:05 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target_);
		RobotomyRequestForm(const RobotomyRequestForm &other_RobotomyRequestForm);
		~RobotomyRequestForm();

		RobotomyRequestForm			&operator=(const RobotomyRequestForm &other_RobotomyRequestForm);
		
		const std::string	&getTarget() const;

		void		execute(Bureaucrat const & executor) const;

	private :
	
		std::string	target;
};

#endif