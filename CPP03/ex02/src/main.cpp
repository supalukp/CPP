/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:11:08 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/06 00:28:32 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main ( void ) {

    FragTrap fragA("frag A");
    
    fragA.attack("Mr.B");
    fragA.takeDamage(30);
    fragA.beRepaired(10);
    fragA.highFivesGuys();
    
    return (0);
}
