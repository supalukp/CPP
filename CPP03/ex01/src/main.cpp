/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/12 17:55:19 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void) {

    // Test default constructors
    std::cout << "---- Test default constructors ----" << std::endl;
    ClapTrap clap1;
    ScavTrap scav1;

    std::cout << "\n";

    //  Test parameterized constructors
    std::cout << "---- Test parameterized constructors ----" << std::endl;
    ClapTrap clap2("C__C");
    ScavTrap scav2("S__S");

    std::cout << "\n";

    // Test copy constructors
    std::cout << "---- Test copy constructors ----" << std::endl;
    ClapTrap clap3(clap2);
    ScavTrap scav3(scav2); 

    std::cout << "\n";

    // Test assignment operators
    std::cout << "---- Test assignment operators ----" << std::endl;
    ClapTrap clap4;
    clap4 = clap2;            

    ScavTrap scav4;
    scav4 = scav2;     

    std::cout << "\n";

    // Test member functions
    std::cout << "---- Test member functions ----" << std::endl;
    clap2.attack("target1");
    clap2.takeDamage(10);
    clap2.beRepaired(5);

    scav2.attack("target2");
    scav2.guardGate();

    std::cout << "\n";

    std::cout << "---- Destructors will be called automatically ----" << std::endl;
    
    return (0);
}