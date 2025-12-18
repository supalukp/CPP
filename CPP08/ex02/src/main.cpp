/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:23:14 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/18 15:38:32 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
static void printElements(T &c)
{
    std::cout << "Element inside stack = ";
    for (typename T::iterator i = c.begin(); i != c.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
}

int main(void)
{
    std::cout << "\n==============================" << std::endl;
    std::cout << "        Orthodox Form    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        std::cout << "\n---- Test default constructors ----" << std::endl;
        MutantStack<int> a;
        a.push(1);
        a.push(2);
        a.push(3);
        
        printElements(a);
        
        std::cout << "\n---- Test copy constructors ----" << std::endl;
        MutantStack<int> b(a);
        printElements(b);
        
        std::cout << "Modify element in stack b" << std::endl;
        b.pop();
        b.push(43);
        b.push(6);
        b.push(13);
        printElements(b);
    
        std::cout << "\n---- Test assignment operators ----" << std::endl;
        b = a;
        printElements(b);
        
        std::cout << "\n---- Test destructor ----" << std::endl;
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "        Stack function    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        MutantStack<int> a;
        std::cout << "\n---- Test: push() ----" << std::endl;
        a.push(10);
        a.push(20);
        a.push(30);
        printElements(a);

        std::cout << "\n---- Test: pop() ----" << std::endl;
        a.pop();
        printElements(a);
        
        std::cout << "\n---- Test: top() ----" << std::endl;
        a.top() -= 2;
        printElements(a);
        
        std::cout << "\n---- Test: size() ----" << std::endl;
        std::cout << "size: " << a.size() << std::endl;        
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "    MutantStack Iterator    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        MutantStack<int> a;
        a.push(10);
        a.push(20);
        a.push(30);
        printElements(a);
        
        std::cout << "\n---- Test: begin() / end()----" << std::endl;
        MutantStack<int>::iterator it = a.begin();
        MutantStack<int>::iterator ite = a.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::cout << "\n---- Test: rbegin() / rend() ----" << std::endl;
        MutantStack<int>::reverse_iterator rit = a.rbegin();
        MutantStack<int>::reverse_iterator rite = a.rend();
        ++rit;
        --rit; 
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }

        std::cout << "\n---- Test: cbegin() / cend()----" << std::endl;
        MutantStack<int>::const_iterator cit = a.cbegin();
        MutantStack<int>::const_iterator cite = a.cend();
        ++cit;
        --cit;
        while (cit != cite)
        {
            std::cout << *cit << std::endl;
            ++cit;
        }

        std::cout << "\n---- Test: crbegin() / crend() ----" << std::endl;
        MutantStack<int>::const_reverse_iterator crit = a.crbegin();
        MutantStack<int>::const_reverse_iterator crite = a.crend();
        ++crit;
        --crit; 
        while (crit != crite)
        {
            std::cout << *crit << std::endl;
            ++crit;
        }
        std::cout << std::endl;
    }
    std::cout << "\n==============================" << std::endl;
    std::cout << "      Test: from subject    " << std::endl;
    std::cout << "==============================" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    std::cout << "\n--------- End test ---------\n" << std::endl;
    
    return (0);
}
