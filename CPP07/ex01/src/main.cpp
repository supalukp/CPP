/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:40:28 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/08 15:52:31 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST: non const    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Test: int array ---" << std::endl;
        int array[] = {1,2,3,4,5,6,7,8,9,10};
        const int len = 10;
        std::cout << "Original: " << std::endl;
        for (int i = 0; i < len; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
        
        std::cout << "After iter: " << std::endl;
        iter(array, len, &addOne);
        for (int i = 0; i < len; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
    }
    {
        std::cout << "\n--- Test: char array ---" << std::endl;
        char array[] = {'a','b','c','d','e','f','g','h','i','j'};
        std::cout << "Original: " << std::endl;
        const int len = 10;
        for (int i = 0; i < len; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
        
        std::cout << "After iter: " << std::endl;
        iter(array, len, &addOne);
        for (int i = 0; i < len; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
        
    }
    {
        std::cout << "\n--- Test: string ---" << std::endl;
        std::string str = "abcdefghij";
        std::cout << "Original: " << str << std::endl;
        const int len = str.size();
        
        std::cout << "After iter: " << std::endl;
        iter(&str[0], len, &addOne);
        for (int i = 0; i < len; i++)
            std::cout << str[i] << " ";
        std::cout << std::endl;
        
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST: const    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n--- Test: int array ---" << std::endl;
        int array[] = {1,2,3,4,5,6,7,8,9,10};
        const int len = 10;
        std::cout << "Original: " << std::endl;
        for (int i = 0; i < len; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
        
        std::cout << "call iter with ft printValue: " << std::endl;
        iter(array, len, &printValue);
        std::cout << std::endl;
    }
    {
        std::cout << "\n--- Test: char array ---" << std::endl;
        char array[] = {'a','b','c','d','e','f','g','h','i','j'};
        std::cout << "Original: " << std::endl;
        const int len = 10;
        for (int i = 0; i < len; i++)
            std::cout << array[i] << " ";
        std::cout << std::endl;
        
        std::cout << "call iter with ft printValue: " << std::endl;
        iter(array, len, &printValue);
        std::cout << std::endl;
        
    }
    {
        std::cout << "\n--- Test: string ---" << std::endl;
        const std::string str = "abcdefghij";
        std::cout << "Original: " << str << std::endl;
        const int len = str.size();
        
        std::cout << "call iter with ft printValue: " << std::endl;
        iter(&str[0], len, &printValue);
        std::cout << std::endl;
        
    }
    return (0);
}