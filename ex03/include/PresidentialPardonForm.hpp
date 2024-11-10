/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:38:15 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 14:43:50 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public :

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target_);
		PresidentialPardonForm(const PresidentialPardonForm &other_PresidentialPardonForm);
		~PresidentialPardonForm();

		PresidentialPardonForm			&operator=(const PresidentialPardonForm &other_PresidentialPardonForm);

		const std::string	&getTarget() const;

		void		execute(Bureaucrat const &executor) const;

	private :
	
		const std::string	target;
};

#endif