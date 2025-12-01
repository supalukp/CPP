/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:25:28 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/01 15:17:04 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) 
    : AForm("RobotomyRequestForm", 72, 45),
    _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm", 72, 45),
    _target(target)
{
    std::cout << "RobotomyRequestForm constructor called with name and grade" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
    : AForm(other),
    _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout   << _target << " : " 
                << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::executeAction(void) const
{
    if (std::rand() % 2)
        std::cout << "Drilling noises.. " << _target << " has been robotomized." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}
