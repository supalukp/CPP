/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:20:42 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/02 11:26:42 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "    Intern Class   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Default constructor ---" << std::endl;
        Intern a;
                
        std::cout << "\n--- Copy Constructor ---" << std::endl;
        Intern copy(a);
                
        std::cout << "\n--- Assignment Operator ---" << std::endl;
        Intern b;
        b = a;
        
        std::cout << "\n--- Destructor ---" << std::endl;
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "    makeForm(name, target)   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n*** Test: good form name ***" << std::endl;
        std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
        {
            Intern a;
            AForm *form;
            form = a.makeForm("ShrubberyCreationForm", "target1");
            std::cout << *form << std::endl;
            delete form;
        }
        std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
        {
            Intern a;
            AForm *form;
            form = a.makeForm("RobotomyRequestForm", "target2");
            std::cout << *form << std::endl;
            delete form;
        }
        std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
        {
            Intern a;
            AForm *form;
            form = a.makeForm("PresidentialPardonForm", "target3");
            std::cout << *form << std::endl;
            delete form;
        }
    }
    {
        std::cout << "\n*** Test: bad form name ***" << std::endl;
        std::cout << "\n--- random name ---" << std::endl;
        {
            Intern a;
            AForm *form;
            form = a.makeForm("helloworld", "target1");
            if (!form)
                std::cout << "Function return NULL" << std::endl;
        }
        std::cout << "\n--- good name with space (not accepted) ---" << std::endl;
        {
            Intern a;
            AForm *form;
            form = a.makeForm("Roboto my Request Form", "target2");
            if (!form)
                std::cout << "Function return NULL" << std::endl;
        }
        std::cout << "\n--- empty name ---" << std::endl;
        {
            Intern a;
            AForm *form;
            form = a.makeForm("", "target3");
            if (!form)
                std::cout << "Function return NULL" << std::endl;
        }
    }
    std::cout << "\n--- End Test ---" << std::endl;
    
    return (0);
}
