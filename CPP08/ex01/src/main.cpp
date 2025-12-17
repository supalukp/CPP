/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:05:12 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/17 13:17:45 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <deque>

int main(void)
{
    Span sp = Span(6);
    
    try
    {
        sp.addNumber(3);
        sp.addNumber(80);
        sp.addNumber(17);
        sp.addNumber(20);
        sp.addNumber(100);
        sp.addNumber(120);
        sp.printElements();
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch Exception: " << e.what() << std::endl;
    }
    
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    
    Span copy = Span(6);
    try
    {
        copy.addNumber(111);
        copy.printElements();
        copy.addNumber(a.begin(), a.end());
        copy.printElements();
        copy.addNumber(a.begin(), a.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch Exception: " << e.what() << std::endl;
    }
    
    return (0);
}
