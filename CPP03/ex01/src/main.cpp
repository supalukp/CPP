/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/06 00:24:29 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main ( void ) {

    ScavTrap scavA("Scav A");
    
    scavA.attack("Mr.B");
    scavA.takeDamage(30);
    scavA.beRepaired(10);
    scavA.guardGate();
    
    return (0);
}