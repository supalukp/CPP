/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:22:54 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/09 10:15:42 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
T min(const T &x, const T &y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template <typename T>
T max(const T &x, const T &y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

#endif
