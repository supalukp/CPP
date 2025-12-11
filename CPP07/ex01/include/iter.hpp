/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:17:18 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/11 11:01:52 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T1, typename T2>
void iter(T1 *array, const size_t length, T2 func)
{
    for(size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

#endif
