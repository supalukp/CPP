/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:23:22 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/16 11:00:36 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <set>

int main(void)
{
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

        std::cout << "Element inside vector = ";
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << "\n--- Test: Findable ---" << std::endl;
        int x = 20;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(vec, x) == x)
                std::cout << "easyfind() found " << x  << std::endl;
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
                std::cout << "easyfind() found " << x  << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "        TEST: Deque    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::deque<int> deq;
        deq.push_back(1);
        deq.push_back(2);
        deq.push_back(3);
        deq.push_back(4);
        deq.push_back(5);

        std::cout << "Element inside deque = ";
        for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << "\n--- Test: Findable ---" << std::endl;
        int x = 3;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(deq, x) == x)
                std::cout << "easyfind() found " << x  << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\n--- Test: Not findable ---" << std::endl;
        x = 6;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(deq, x) == x)
                std::cout << "easyfind() found " << x  << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "        TEST: List    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::list<int> list;
        list.push_back(111);
        list.push_back(12565);
        list.push_back(3544);
        list.push_back(45484);
        list.push_back(44515);

        std::cout << "Element inside list = ";
        for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << "\n--- Test: Findable ---" << std::endl;
        int x = 44515;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(list, x) == x)
                std::cout << "easyfind() found " << x  << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\n--- Delete last element" << std::endl;
        list.pop_back();
        std::cout << "Element inside list = ";
        for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        std::cout << "\n--- Test: Not findable ---" << std::endl;
        x = 44515;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(list, x) == x)
                std::cout << "easyfind() found " << x  << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "        TEST: Set    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::set<int> set;
        set.insert(0);
        set.insert(5);
        set.insert(8);
        set.insert(1);
        set.insert(20);

        std::cout << "Element inside set = ";
        for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
        
        std::cout << "\n--- Test: Findable ---" << std::endl;
        int x = 5;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(set, x) == x)
                std::cout << "easyfind() found " << x  << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        std::cout << "\n--- Test: Not findable ---" << std::endl;
        x = 10;
        try
        {
            std::cout << "Try to find " << x << std::endl;
            if (easyfind(set, x) == x)
                std::cout << "easyfind() found " << x  << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
        std::cout << "\n--- End of the test ---" << std::endl;

    return (0);
}
