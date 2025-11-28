/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:25:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/28 09:39:54 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target)
{
    std::cout << "PresidentialPardonForm constructor called with name and grade" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout   << _target << " : " 
                << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::executeAction(void) const
{
    // Informs that <target> has been pardoned by Zaphod Beeblebrox.
}
