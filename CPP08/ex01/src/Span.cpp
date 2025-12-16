/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:09 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/16 12:38:51 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Span::Span(unsigned int n) : _n(n)
{
    std::cout << "Constructor with parameter called" << std::endl;
}
Span::Span(const Span &other) : _n(other._n)
{
    std::cout << "Copy constructor called" << std::endl;
}

Span& Span::operator=(const Span &other)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &other)
    {
        this->_n = other._n;   
    }
    return (*this);
}

Span::~Span(void)
{
    std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int value)
{
    std::cout << "size: " << _c.size() << std::endl;
    if (_c.size() < _n)
        _c.push_back(value);
    else
        throw std::out_of_range("Out of range");
}

int Span::shortestSpan(void)
{
    
}

int Span::longestSpan(void)
{
    
}

void Span::printElements(void)
{
    for (std::vector<int>::iterator i = _c.begin(); i != _c.end(); i++)
        std::cout << *i << std::endl;
}
