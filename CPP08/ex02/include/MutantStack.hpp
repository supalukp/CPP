/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:23:10 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/18 15:34:47 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack &other);
        ~MutantStack();
        
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        
        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;

        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;

        reverse_iterator rbegin();
        reverse_iterator rend();
};

#include "MutantStack.tpp"

#endif
