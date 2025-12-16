/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:05:12 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/16 12:32:01 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    Span sp = Span(6);
    
    try
    {
        sp.addNumber(3);
        sp.addNumber(6);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(12);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch Exception: " << e.what() << std::endl;
    }
    sp.printElements();
    
    return (0);
}
