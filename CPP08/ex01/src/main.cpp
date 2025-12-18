/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:05:12 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/18 16:39:34 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <deque>

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "        Orthodox Form    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n---- Test default constructors ----" << std::endl;
        Span def = Span();
        
        std::cout << "\n---- Test constructor with parameter ----" << std::endl;
        Span sp = Span(5);
        try
        {
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
            sp.addNumber(5);
            sp.printElements();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << "\n---- Test copy constructors ----" << std::endl;
        Span copy(sp);
        copy.printElements();
    
        std::cout << "\n---- Test assignment operators ----" << std::endl;
        def = sp;
        def.printElements();
        
        std::cout << "\n---- Test destructor ----" << std::endl;
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "        Member function    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        Span sp = Span(6);
        try
        {
            std::cout << "\n---- Test: addNumber ----" << std::endl;
            sp.addNumber(3);
            sp.addNumber(80);
            sp.addNumber(17);
            sp.addNumber(20);
            sp.addNumber(100);
            sp.addNumber(120);
            sp.printElements();
            std::cout << "\n---- Test: longestSpan() ----" << std::endl;
            std::cout << "Longest: " << sp.longestSpan() << std::endl;
            std::cout << "\n---- Test: shortestSpan() ----" << std::endl;
            std::cout << "Shortest: " << sp.shortestSpan() << std::endl;

            std::cout << "\n---- Test: addNumber (Error) ----" << std::endl;
            sp.addNumber(123);
            sp.printElements();
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception: " << e.what() << std::endl;
        }
        std::cout << std::endl;
        
        std::cout << "\n---- Test: addNumber (range of iterators) ----" << std::endl;
        std::vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
    
        Span copy = Span(6);
        try
        {
            copy.addNumber(10);
            copy.printElements();
            copy.addNumber(a.begin(), a.end());
            copy.printElements();
            
            std::cout << "\n---- Test: addNumber (not enough space to add) ----" << std::endl;
            copy.addNumber(a.begin(), a.end());
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception: " << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
    return (0);
}
