/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:10:52 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/08 17:10:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
        
    public:
        
        Array(void);
        Array(unsigned int n);
        Array(const Array &other);
        Array& operator=(const Array& other);
        ~Array(void);

        unsigned int size() const;
};

#include "Array.tpp"

#endif
