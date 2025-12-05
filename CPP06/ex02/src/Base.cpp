/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:15:28 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/05 16:29:58 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) { }

Base* generate(void)
{
    int random = std::rand() % 3;
    
    if (random == 0)
        return (new A);
    else if (random == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
    if (a)
        std::cout << "p: \"A\"" << std::endl;
        
    B* b = dynamic_cast<B*>(p);
    if (b)
        std::cout << "p: \"B\"" << std::endl;
        
    C* c = dynamic_cast<C*>(p);
    if (c)
        std::cout << "p: \"C\"" << std::endl;   
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "p: \"A\"" << std::endl;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << std::endl;
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "p: \"B\"" << std::endl;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << std::endl;
    }
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "p: \"C\"" << std::endl;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << std::endl;
    }
}