/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/12 12:24:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void) {
    
    ClapTrap a("A");
    ClapTrap b("B");
    
    a.attack("B");
    b.takeDamage(5);
    b.beRepaired(3);
    b.attack("A");
    
    return (0);
}
