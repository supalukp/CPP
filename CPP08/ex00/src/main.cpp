/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:23:22 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/15 15:41:33 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <array>
#include <iostream>

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "        TEST: Array     " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "        TEST: Vector    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        std::cout << "Element inside vetor = ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << "\n--- Test: Findable ---" << std::endl;
        int x = 20;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(vec, x) == x)
                std::cout << "easyfind() found x" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\n--- Test: Not findable ---" << std::endl;
        x = 80;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(vec, x) == x)
                std::cout << "easyfind() found x" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    return (0);
}
