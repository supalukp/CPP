/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:44:48 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/02 11:28:38 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
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

const char* Intern::nameNotValid::what() const throw()
{
    return ("Form name is not valid");
}

AForm *Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
    std::string valid_name[] = {"ShrubberyCreationForm",
                                "RobotomyRequestForm",
                                "PresidentialPardonForm"};
    int i = 0;
    while (i < 3)
    {
        if (formName == valid_name[i])
            break ;

        i++;
    }
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl;
            return (new ShrubberyCreationForm(formTarget));
        case 1:
            std::cout << "Intern creates " << formName << std::endl;
            return (new RobotomyRequestForm(formTarget));
        case 2:
            std::cout << "Intern creates " << formName << std::endl;
            return (new PresidentialPardonForm(formTarget));
        default:
            std::cout << "No form name matched" << std::endl;
            return (NULL);
    }
}
