/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/13 10:50:34 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void) {
    
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

    std::cout << "\n--- DiamondTrap Test --" << std::endl;
    // DiamondTrap dia("DIAMOND");
    
    // dia.attack("target4");
    // dia.takeDamage(40);
    // dia.beRepaired(15);
    // dia.whoAmI();
    // dia.highFivesGuys();
    // dia.guardGate();
    {
        std::cout << "\n--- Default Constructor ---" << std::endl;
        DiamondTrap d1;
        d1.whoAmI();
    }

    std::cout << "\n--- Parameterized Constructor ---" << std::endl;
    DiamondTrap d2("DIAMOND"); 
    d2.attack("target1");
    d2.takeDamage(20);
    d2.beRepaired(10);
    d2.whoAmI();
    d2.highFivesGuys();
    d2.guardGate();

    std::cout << "\n--- Copy Constructor ---" << std::endl;
    DiamondTrap d3(d2);
    d3.whoAmI();
    d3.attack("target2");

    std::cout << "\n--- Copy Assignment ---" << std::endl;
    DiamondTrap d4("ANOTHER");
    d4 = d2;        
    d4.whoAmI();
    d4.attack("target3");

    std::cout << "\n--- Destructors will be called automatically  ---\n" << std::endl;
    
    return (0);
}