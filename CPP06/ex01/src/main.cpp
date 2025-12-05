/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:09:51 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/05 14:02:18 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
    Data *a = new Data;
    
    a->x = 42;
    std::cout << a << std::endl;

    uintptr_t b = Serializer::serialize(a);
    std::cout << b << std::endl;
    
    Data* c = Serializer::deserialize(b);
    std::cout << c->x << std::endl;

    std::cout << Serializer::deserialize(b) << std::endl;
    if (a == Serializer::deserialize(b))
        std::cout << "Same pointer" << std::endl;
    else
        std::cout << "Different pointer" << std::endl;
    delete a;
    
    return (0);
}
