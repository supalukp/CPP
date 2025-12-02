/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:44:48 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/02 14:28:08 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
    funct[0] = &Intern::makeShrubbery;
    funct[1] = &Intern::makeRobotomy;
    funct[2] = &Intern::makePresidential;

    validName[0] = "ShrubberyCreationForm";
    validName[1] = "RobotomyRequestForm";
    validName[2] = "PresidentialPardonForm";
    
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;   
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string const formName, std::string const formTarget)
{
    for (int i = 0; i < 3; i++)
	{
		if (validName[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
			return ((this->*funct[i])(formTarget));
        }
	}
    
    std::cout << "No form name matched" << std::endl;
    return (NULL);
}
