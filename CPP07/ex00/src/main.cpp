/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:22:40 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/10 12:42:19 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
    std::cout << "==============================" << std::endl;
    std::cout << "      TEST FOR SWAP      " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\nSWAP: int" << std::endl;
        int x = 5;
        int y = 20;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "After swap: " << std::endl;
        ::swap(x,y);
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    }
    {
        std::cout << "\nSWAP: float" << std::endl;
        float x = 5.5f;
        float y = 20.35f;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "After swap: " << std::endl;
        ::swap(x,y);
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    }
    {
        std::cout << "\nSWAP: string" << std::endl;
        std::string x = "hello";
        std::string y = "world";
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "After swap: " << std::endl;
        ::swap(x,y);
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST FOR MIN     " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\nMIN: int" << std::endl;
        int x = 5;
        int y = 20;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "min of (x, y) = " << ::min(x,y) << std::endl;
    }
    {
        std::cout << "\nMIN: float" << std::endl;
        float x = 105.5f;
        float y = 20.35f;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "min of (x, y) = " << ::min(x,y) << std::endl;
    }
    {
        std::cout << "\nMIN: string" << std::endl;
        std::string x = "hello";
        std::string y = "hello";
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "min of (x, y) = " << ::min(x,y) << std::endl;
    }
    
    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST FOR MAX     " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\nMAX: int" << std::endl;
        int x = 5;
        int y = 20;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "max of (x, y) = " << ::max(x,y) << std::endl;
    }
    {
        std::cout << "\nMAX: float" << std::endl;
        float x = 105.5f;
        float y = 20.35f;
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "max of (x, y) = " << ::max(x,y) << std::endl;
    }
    {
        std::cout << "\nMAX: string" << std::endl;
        std::string x = "hello";
        std::string y = "hello";
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "max of (x, y) = " << ::max(x,y) << std::endl;
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "      TEST FORM SUBJECT     " << std::endl;
    std::cout << "==============================" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    std::cout << "\n-------- End test ---------" << std::endl;
    return (0);
}
