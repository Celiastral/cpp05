/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:34:48 by eandre            #+#    #+#             */
/*   Updated: 2024/11/10 15:29:13 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target_);
		ShrubberyCreationForm(const ShrubberyCreationForm &other_ShrubberyCreationForm);
		~ShrubberyCreationForm();

		ShrubberyCreationForm			&operator=(const ShrubberyCreationForm &other_ShrubberyCreationForm);

		const std::string	&getTarget() const;

		void		execute(Bureaucrat const & executor) const;

	private :
	
		std::string	target;
};

#endif