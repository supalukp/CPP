/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:56:32 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/22 10:46:49 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string typeName ) 
{
    _type = typeName;
}

Weapon::~Weapon( void ) {}
        
const std::string& Weapon::getType( void ) const { return (_type); }

void Weapon::setType( std::string newType )
{
    _type = newType;
}
