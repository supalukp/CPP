/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:11:21 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/11 12:39:37 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <climits>
#include <float.h>

struct Data
{
    int x;
};

int main (void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "         Type : INT   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n---- Test default constructors ----" << std::endl;
        Array <int>a;
        std::cout << "size of a = " << a.size() << std::endl;

        std::cout << "\n---- Test parameterized constructors ----" << std::endl;
        Array <int>b(5);
        std::cout << "size of b = " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = i+1;
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        
        std::cout << "\n---- Test copy constructors ----" << std::endl;
        Array <int>copy(b);
        std::cout << "size of copy from b = " << copy.size() << std::endl;
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << "\n";

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

        std::cout << "---------------------------------" << std::endl;
        
        std::cout << "\n*** Copy from same size array ***" << std::endl;
        Array <int>same(5);
        for (unsigned int i = 0; i < same.size(); i++)
            same[i] = 10 - i;
        std::cout << "Original same: ";
        for (unsigned int i = 0; i < same.size(); i++)
            std::cout << same[i] << " ";
        std::cout << "\n";
        std::cout << "Original b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        
        same = b;
        std::cout << "After copy from b: ";
        for (unsigned int i = 0; i < same.size(); i++)
            std::cout << same[i] << " ";
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
    std::cout << "\n==============================" << std::endl;
    std::cout << "         Type : CHAR   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n---- Test default constructors ----" << std::endl;
        Array <char>a;
        std::cout << "size of a = " << a.size() << std::endl;

        std::cout << "\n---- Test parameterized constructors ----" << std::endl;
        Array <char>b(5);
        std::cout << "size of b = " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); i++)
            b[i] = 'a'+ i;
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << "\n";
        
        std::cout << "\n---- Test copy constructors ----" << std::endl;
        Array <char>copy(b);
        std::cout << "size of copy from b = " << copy.size() << std::endl;
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << "\n";

        std::cout << "\n---- Test assignment operators ----" << std::endl;
        
        std::cout << "\n*** Copy from smaller array ***" << std::endl;
        Array <char>big(10);
        for (unsigned int i = 0; i < big.size(); i++)
            big[i] = 'A' + i;
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
        Array <char>small(2);
        for (unsigned int i = 0; i < small.size(); i++)
            small[i] = 'A' + i;
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
            b[0] = 'A';
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
            b[b.size()] = 'Z';
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
    std::cout << "\n==============================" << std::endl;
    std::cout << "   Try with different type   " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n---- Type: int ----" << std::endl;
        Array <int>a(5);
        std::cout << "size of a = " << a.size() << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i + 1;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << "\n";
    }
    {
        std::cout << "\n---- Type: char ----" << std::endl;
        Array <char>a(5);
        std::cout << "size of a = " << a.size() << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = 'a' + i;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << "\n";
    }
    {
        std::cout << "\n---- Type: float ----" << std::endl;
        Array <float>a(5);
        std::cout << "size of a = " << a.size() << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = FLT_MAX - i;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << "\n";
    }
    {
        std::cout << "\n---- Type: double ----" << std::endl;
        Array <double>a(5);
        std::cout << "size of a = " << a.size() << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = DBL_MAX - i;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << "\n";
    }
    {
        std::cout << "\n---- Type: long ----" << std::endl;
        Array <long>a(5);
        std::cout << "size of a = " << a.size() << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = LONG_MAX - i;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << "\n";
    }
    {
        std::cout << "\n---- Type: struct ----" << std::endl;
        Array <Data>a(5);
        std::cout << "size of a = " << a.size() << std::endl;
        for (unsigned int i = 0; i < a.size(); i++)
            a[i].x = 1 + i;
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i].x << " ";
        std::cout << "\n";
    }
    std::cout << "\n----------- End test ------------" << std::endl;
    
    return (0);
}
