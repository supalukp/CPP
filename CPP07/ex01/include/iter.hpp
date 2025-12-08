/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:17:18 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/08 16:07:54 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, const size_t length, void (*func)(T&))
{
    for(size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(const T *array, const size_t length, void (*func)(const T&))
{
    for(size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T, typename F>
void iter(T *array, const size_t length, F (*func)(T&))
{
    for(size_t i = 0; i < length; i++)
    {
        std::cout << func(array[i]) << " ";
    }
}

int minusOne(int &x)
{
    return (x - 1);
}

template <typename T>
void addOne(T &x)
{
    x += 1;
}

template <typename T>
void printValue(const T &x) 
{
    std::cout << x << "-";
}

#endif
