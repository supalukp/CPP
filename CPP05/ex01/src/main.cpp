/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:03:21 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/01 14:57:44 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST FOR FORM      " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Default constructor ---" << std::endl;
        Form a;
        std::cout << a << std::endl;
        
        std::cout << "\n--- Constructor with parameter ---" << std::endl;
        Form b("B", 1, 1);
        std::cout << b << std::endl;

        std::cout << "\n--- Constructor with parameter grade too high ---" << std::endl;
        try
        {
            Form high("Too high", 0, 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception Too High: " << e.what() << std::endl;
        }
        
        std::cout << "\n--- Constructor with parameter grade too low ---" << std::endl;
        try
        {
            Form low("Too low", 151, 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception Too Low: " << e.what() << std::endl;
        }
        
        std::cout << "\n--- Copy Constructor ---" << std::endl;
        Form copy(b);
        std::cout << copy << std::endl;
        
        std::cout << "\n--- Assignment Operator ---" << std::endl;
        a = b;
        std::cout << a << std::endl;

        std::cout << "\n--- Destructor ---" << std::endl;
    }

    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST beSigned()     " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Test: bureaucrat´s grade is high enough ---" << std::endl;
        Form b("B", 50, 50);
        Bureaucrat a("A", 1);
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        try
        {
            b.beSigned(a);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception beSigned(): " << e.what() << std::endl;
        }
        std::cout << b << std::endl;
    }
    {
        std::cout << "\n--- Test: bureaucrat´s grade is equal ---" << std::endl;
        Form b("B", 50, 50);
        Bureaucrat a("A", 50);
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        try
        {
            b.beSigned(a);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception beSigned(): " << e.what() << std::endl;
        }
        std::cout << b << std::endl;
    }
    {
        std::cout << "\n--- Test: bureaucrat´s grade is lower ---" << std::endl;
        Form b("B", 50, 50);
        Bureaucrat a("A", 150);
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        try
        {
            b.beSigned(a);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception beSigned(): " << e.what() << std::endl;
        }
        std::cout << b << std::endl;
    }

    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST signForm()     " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Test: bureaucrat´s grade is high enough ---" << std::endl;
        Form b("B", 50, 50);
        Bureaucrat a("Bureaucrat A", 50);
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        try
        {
            a.signForm(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception signForm(): " << e.what() << std::endl;
        }
        std::cout << b << std::endl;
    }
    {
        std::cout << "\n--- Test: bureaucrat´s grade is equal ---" << std::endl;
        Form b("B", 50, 50);
        Bureaucrat a("Bureaucrat A", 1);
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        try
        {
            a.signForm(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception signForm(): " << e.what() << std::endl;
        }
        std::cout << b << std::endl;
    }
    {
        std::cout << "\n--- Test: bureaucrat´s grade is lower ---" << std::endl;
        Form b("B", 50, 50);
        Bureaucrat a("Bureaucrat A", 150);
        std::cout << b << std::endl;
        std::cout << a << std::endl;

        try
        {
            a.signForm(b);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception signForm(): " << e.what() << std::endl;
        }
        std::cout << b << std::endl;
    }
    std::cout << "\n--- End Test ---" << std::endl;
    
    return (0);
}
