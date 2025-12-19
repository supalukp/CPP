/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:12 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/19 09:30:06 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _c;
        
    public:
        Span(void);
        Span(unsigned int n);
        Span(const Span &other);
        Span& operator=(const Span &other);
        ~Span(void);
        
        // add number
        void    addNumber(int value);
        
        template <typename Iterator>
        void addNumber(Iterator begin, Iterator end)
        {
            unsigned int add_size = std::distance(begin, end);
            if (_c.size() + add_size > _n)
                throw std::length_error("The range is too big too add number");
            for (Iterator it = begin; it != end; it++)
                addNumber(*it);
        }
        
        // shortest / longest span
        int     shortestSpan(void);
        int     longestSpan(void);
        
        // print elements 
        void    printElements(void);
        
        // exception
        class NotEnoughElements : public std::exception 
        {
            public:
                virtual const char* what() const throw();
        };
        
};

#endif
