/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:59:16 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/18 15:34:38 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() 
{
    std::cout << "Default constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other)
{
    std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (*this != other)
    {
        std::stack<T>::operator=(other);
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{
    std::cout << "Destructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crbegin() const
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::crend() const
{
    return (this->c.rend());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}
