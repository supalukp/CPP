/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:25:28 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/02 12:36:09 by spunyapr         ###   ########.fr       */
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
    std::cout << "Drilling noises.. " << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << "The robotomy of target " << _target <<  " failed." << std::endl;
}
