/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:57:10 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/05 13:44:52 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) { }

Serializer::~Serializer(void) { }

Serializer::Serializer(const Serializer &other)
{
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    (void) other;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t res = reinterpret_cast<uintptr_t>(ptr);
    return (res);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *res;
    res = reinterpret_cast<Data *>(raw);
    return (res);
}
