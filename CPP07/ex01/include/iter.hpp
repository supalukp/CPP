/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:17:18 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/08 15:51:01 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, const size_t lenght, void (*func)(T &))
{
    for(size_t i = 0; i < lenght; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(const T *array, const size_t lenght, void (*func)(const T &))
{
    for(size_t i = 0; i < lenght; i++)
    {
        func(array[i]);
    }
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
