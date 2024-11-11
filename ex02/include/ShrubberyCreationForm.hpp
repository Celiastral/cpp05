/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:34:48 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 11:27:17 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public :

		//=== Orthodox class mandatory ===

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target_);
		ShrubberyCreationForm(const ShrubberyCreationForm &other_ShrubberyCreationForm);
		~ShrubberyCreationForm();

		ShrubberyCreationForm			&operator=(const ShrubberyCreationForm &other_ShrubberyCreationForm);

		//=== Getter ===

		const std::string	&getTarget() const;

		//=== Form interaction ===

		void		execute(Bureaucrat const & executor) const;

	private :
	
		std::string	target;
};

#endif