/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:05:12 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/17 11:41:24 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch Exception: " << e.what() << std::endl;
    }
    sp.printElements();
    std::cout << "Longest: " << sp.longestSpan() << std::endl;
    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;

    sp.printElements();
    
    return (0);
}
