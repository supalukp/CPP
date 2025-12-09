/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:11:21 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/09 14:00:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main (void)
{
    Array <int>int_array(2);
    std::cout << int_array.size() << std::endl;
    try 
    {
        std::cout << "array[1] = "<< int_array[1] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch Exception: " << e.what() << std::endl;
    }
    
    Array <int>try_array;
    std::cout << try_array.size() << std::endl;
    
    int *a = new int(20);
    std::cout << *a << std::endl;
    delete a;
    
    return (0);
}
