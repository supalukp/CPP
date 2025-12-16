/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:04:12 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/16 12:38:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

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
        
        void addNumber(int value);
        
        int shortestSpan(void);
        int longestSpan(void);

        void printElements(void);
        
};

#endif
