/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:11:21 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/09 17:14:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main (void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "         Type : INT   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        // Test default constructors
        std::cout << "\n---- Test default constructors ----" << std::endl;
        Array <int>a;
        std::cout << "size of a = " << a.size() << std::endl;

        //  Test parameterized constructors
        std::cout << "\n---- Test parameterized constructors ----" << std::endl;
        Array <int>b(5);
        std::cout << "size of b = " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i+1;
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        
        // Test copy constructors
        std::cout << "\n---- Test copy constructors ----" << std::endl;
        Array <int>copy(b);
        std::cout << "size of copy from b = " << copy.size() << std::endl;
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << "\n";

        // Test assignment operators
        std::cout << "\n---- Test assignment operators ----" << std::endl;
        
        std::cout << "\n*** Copy from smaller array ***" << std::endl;
        Array <int>big(10);
        for (unsigned int i = 0; i < big.size(); i++)
            big[i] = 10 - i;
        std::cout << "Original big: ";
        for (unsigned int i = 0; i < big.size(); i++)
            std::cout << big[i] << " ";
        std::cout << "\n";
        std::cout << "Original b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        
        big = b;
        std::cout << "After copy from b: ";
        for (unsigned int i = 0; i < big.size(); i++)
            std::cout << big[i] << " ";
        std::cout << "\n";
        
        std::cout << "---------------------------------" << std::endl;
        
        std::cout << "\n*** Copy from bigger array ***" << std::endl;
        Array <int>small(2);
        for (unsigned int i = 0; i < small.size(); i++)
            small[i] = 10 - i;
        std::cout << "Original small: ";
        for (unsigned int i = 0; i < small.size(); i++)
            std::cout << small[i] << " ";
        std::cout << "\n";
        std::cout << "Original b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        
        small = b;
        std::cout << "After copy from b: ";
        for (unsigned int i = 0; i < small.size(); i++)
            std::cout << small[i] << " ";
        std::cout << "\n";

        std::cout << "\n---- Test subscript operator[] ----" << std::endl;
        std::cout << "Original b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        std::cout << " < Try to modify 1st element to 100 >" << std::endl;
        try
        {
            b[0] = 100;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception: " << e.what() << std::endl;
        }
        std::cout << "After modify b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";

        std::cout << "\n---- Test subscript operator[] ----" << std::endl;
        std::cout << "size of b = " << b.size() << std::endl;
        std::cout << " < Try to modify index out of range >" << std::endl;
        try
        {
            b[b.size()] = 100;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Catch Exception: " << e.what() << std::endl;
        }
        std::cout << "After failed to modify b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";

        std::cout << "\n---- Test size() ----" << std::endl;
        std::cout << "Elements in b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        std::cout << "size of b = " << b.size() << std::endl;

        std::cout << "\n----------- Destructor ------------" << std::endl;
    }
    {
        
    }

    std::cout << "\n----------- End test ------------" << std::endl;
    
    return (0);
}
