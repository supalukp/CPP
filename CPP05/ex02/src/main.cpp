/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 09:20:42 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/01 17:15:31 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "    ShrubberyCreationForm   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- S: Default constructor ---" << std::endl;
        ShrubberyCreationForm a;
        std::cout << a << std::endl;
        
        std::cout << "\n--- S: Constructor with parameter ---" << std::endl;
        ShrubberyCreationForm b("B");
        std::cout << b << std::endl;
        
        std::cout << "\n--- S: Copy Constructor ---" << std::endl;
        ShrubberyCreationForm copy(b);
        std::cout << copy << std::endl;
        
        std::cout << "\n--- S: Assignment Operator ---" << std::endl;
        a = b;
        std::cout << a << std::endl;

        std::cout << "\n--- S: Destructor ---" << std::endl;
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "    Shrubbery: execute()   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        
        ShrubberyCreationForm a("home");
        Bureaucrat b("B", 137);
        std::cout << "\n--- Test: not signed form ---" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        try
        {
            a.execute(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception execute(): " << e.what() << std::endl;
        }

        std::cout << "\n--- Test: signed form ---" << std::endl;
        try
        {
            b.signForm(a);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception signForm(): " << e.what() << std::endl;
        }
        try
        {
            a.execute(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception execute(): " << e.what() << std::endl;
        }

        std::cout << "\n--- Test: grade too low ---" << std::endl;
        b.decreaseGrade();
        std::cout << b << std::endl;
        
        try
        {
            a.execute(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception execute(): " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n==============================" << std::endl;
    std::cout << "    RobotomyRequestForm   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Default constructor ---" << std::endl;
        RobotomyRequestForm a;
        std::cout << a << std::endl;
        
        std::cout << "\n--- Constructor with parameter ---" << std::endl;
        RobotomyRequestForm b("B");
        std::cout << b << std::endl;
        
        std::cout << "\n--- Copy Constructor ---" << std::endl;
        RobotomyRequestForm copy(b);
        std::cout << copy << std::endl;
        
        std::cout << "\n--- Assignment Operator ---" << std::endl;
        a = b;
        std::cout << a << std::endl;

        std::cout << "\n--- Destructor ---" << std::endl;
    }
    
    std::cout << "\n==============================" << std::endl;
    std::cout << "  RobotomyRequestForm: execute()  " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        
        ShrubberyCreationForm a("home");
        Bureaucrat b("B", 137);
        std::cout << "\n--- Test: not signed form ---" << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        try
        {
            a.execute(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception execute(): " << e.what() << std::endl;
        }

        std::cout << "\n--- Test: signed form ---" << std::endl;
        try
        {
            b.signForm(a);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception signForm(): " << e.what() << std::endl;
        }
        try
        {
            a.execute(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception execute(): " << e.what() << std::endl;
        }

        std::cout << "\n--- Test: grade too low ---" << std::endl;
        b.decreaseGrade();
        std::cout << b << std::endl;
        
        try
        {
            a.execute(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception execute(): " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::cout << "\n==============================" << std::endl;
    std::cout << "    PresidentialPardonForm   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Default constructor ---" << std::endl;
        PresidentialPardonForm a;
        std::cout << a << std::endl;
        
        std::cout << "\n--- Constructor with parameter ---" << std::endl;
        PresidentialPardonForm b("B");
        std::cout << b << std::endl;
        
        std::cout << "\n--- Copy Constructor ---" << std::endl;
        PresidentialPardonForm copy(b);
        std::cout << copy << std::endl;
        
        std::cout << "\n--- Assignment Operator ---" << std::endl;
        a = b;
        std::cout << a << std::endl;

        std::cout << "\n--- Destructor ---" << std::endl;
    }
    return (0);
}
