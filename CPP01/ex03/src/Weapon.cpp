/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:56:32 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/20 18:52:11 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string typeName) 
{
    _type = typeName;
}

Weapon::~Weapon() {}
        
const std::string& Weapon::getType() const { return (_type); }

void Weapon::setType(std::string newType)
{
    _type = newType;
}
