/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/06 00:16:29 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
    std::cout << "\n--- ClapTrap Test ---" << std::endl;
    ClapTrap clap("CLAP");
    clap.attack("target1");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n--- ScavTrap Test ---" << std::endl;
    ScavTrap scav("SCAV");
    scav.attack("target2");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n--- FragTrap Test ---" << std::endl;
    FragTrap frag("FRAG");
    frag.attack("target3");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n--- DiamondTrap Test ---" << std::endl;
    DiamondTrap dia("DIAMOND");
    dia.attack("target4");
    dia.takeDamage(40);
    dia.beRepaired(15);
    dia.whoAmI();
    dia.highFivesGuys();
    dia.guardGate();

    std::cout << "\n--- END ---\n" << std::endl;
    return 0;
}