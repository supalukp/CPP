/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:09 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/19 09:33:43 by spunyapr         ###   ########.fr       */
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

Span::Span(const Span &other) : _n(other._n), _c(other._c)
{
    std::cout << "Copy constructor called" << std::endl;
}

Span& Span::operator=(const Span &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_n = other._n;
        this->_c = other._c;  
    }
    return (*this);
}

Span::~Span(void)
{
    std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int value)
{
    if (_c.size() < _n)
        _c.push_back(value);
    else
        throw std::out_of_range("Span is already full");
}

int Span::shortestSpan(void)
{
    if (_c.size() < 2)
        throw NotEnoughElements();
    std::vector<int> tmp(_c.size());
    std::copy(_c.begin(), _c.end(), tmp.begin());
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (std::vector<int>::iterator it = tmp.begin(); it + 1 != tmp.end(); it++)
    {
        if ((*(it + 1) - *it) < min)
            min = *(it + 1) - *it;
    }
    return (min);
}

int Span::longestSpan(void)
{
    if (_c.size() < 2)
        throw NotEnoughElements();
    std::vector<int>::iterator max = std::max_element(_c.begin(), _c.end());
    std::vector<int>::iterator min = std::min_element(_c.begin(), _c.end());
    return (*max - *min);
}

void Span::printElements(void) const
{
    std::cout << "Elements: ";
    for (std::vector<int>::const_iterator i = _c.begin(); i != _c.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
}

const char* Span::NotEnoughElements::what() const throw()
{
    return ("Not enough elements to compare");
}
