/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 20:18:05 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/21 11:26:34 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria* _inventory[4];
        static const int MAX_FLOOR = 100;
        AMateria* _floor[MAX_FLOOR];
        int _floorCount;
    
    public:
        Character(void); // Default constructor
        Character(std::string newName); // Parameterized constructor
        Character(const Character& other); // Copy constructor
        Character& operator=(const Character& other); // Copy assignment operator
        ~Character(void); // Destructor

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        
};

#endif
