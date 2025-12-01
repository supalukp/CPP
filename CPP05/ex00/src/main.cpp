/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/01 17:29:10 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST FOR BUREAUCRAT      " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Default constructor ---" << std::endl;
        Bureaucrat a;
        std::cout << a << std::endl;
        
        
        std::cout << "\n--- Constructor with parameter ---" << std::endl;
        Bureaucrat b("B", 1);
        std::cout << b << std::endl;

        std::cout << "\n--- Constructor with parameter grade too high ---" << std::endl;
        try
        {
            Bureaucrat high("Too high", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception Too High: " << e.what() << std::endl;
        }

        std::cout << "\n--- Constructor with parameter grade too low ---" << std::endl;
        try
        {
            Bureaucrat low("Too low", 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception Too Low: " << e.what() << std::endl;
        }
        
        std::cout << "\n--- Copy Constructor ---" << std::endl;
        Bureaucrat c(b);
        std::cout << c << std::endl;

        std::cout << "\n--- Assignment Operator ---" << std::endl;
        a = b;
        std::cout << a << std::endl;

        std::cout << "\n--- Destructor ---" << std::endl;
    }
    std::cout << "\n\n==============================" << std::endl;
    std::cout << "   TEST FOR INCRESE GRADE   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Grade 1 ---" << std::endl;
        Bureaucrat a("A", 1);
        std::cout << a << std::endl;
        
        try
        {
            a.increaseGrade();
            std::cout << a << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception A: "<< e.what() << std::endl;
        }
    }
    {
        std::cout << "\n--- Grade 150 ---" << std::endl;
        Bureaucrat b("B", 150);
        std::cout << b << std::endl;
        try
        {
            b.increaseGrade();
            std::cout << b << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception B: "<< e.what() << std::endl;
        }
    }
    std::cout << "\n\n==============================" << std::endl;
    std::cout << "   TEST FOR DECEASE GRADE   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Grade 1 ---" << std::endl;
        Bureaucrat a("A", 1);
        std::cout << a << std::endl;
        
        try
        {
            a.decreaseGrade();
            std::cout << a << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception A: "<< e.what() << std::endl;
        }
    }
    {
        std::cout << "\n--- Grade 150 ---" << std::endl;
        Bureaucrat b("B", 150);
        std::cout << b << std::endl;
        try
        {
            b.decreaseGrade();
            std::cout << b << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception B: "<< e.what() << std::endl;
        }
    }
    std::cout << "\n--- End Test ---" << std::endl;
    return (0);
}
