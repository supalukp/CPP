/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/12 17:58:35 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    
    // Test default constructors
    std::cout << "---- Test default constructors ----" << std::endl;
    ClapTrap clap1;
    ScavTrap scav1;
    FragTrap frag1;

    std::cout << "\n";

    //  Test parameterized constructors
    std::cout << "---- Test parameterized constructors ----" << std::endl;
    ClapTrap clap2("C__C");
    ScavTrap scav2("S__S");
    FragTrap frag2("F__F");

    std::cout << "\n";

    // Test copy constructors
    std::cout << "---- Test copy constructors ----" << std::endl;
    ClapTrap clap3(clap2);
    ScavTrap scav3(scav2);
    FragTrap frag3(frag2);

    std::cout << "\n";

    // Test assignment operators
    std::cout << "---- Test assignment operators ----" << std::endl;
    ClapTrap clap4;
    clap4 = clap2;

    ScavTrap scav4;
    scav4 = scav2;

    FragTrap frag4;
    frag4 = frag2;

    std::cout << "\n";

    // Test member functions
    std::cout << "---- Test member functions ----" << std::endl;
    clap2.attack("Target1");
    clap2.takeDamage(15);
    clap2.beRepaired(10);

    scav2.attack("Target2");
    scav2.guardGate();

    frag2.attack("Target3");
    frag2.highFivesGuys();

    std::cout << "\n";

    std::cout << "---- Destructors will be called automatically ----" << std::endl;
    
    return (0);
}
