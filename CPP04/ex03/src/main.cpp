/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:40:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/21 12:16:35 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp" 
#include "Ice.hpp"  
#include "Cure.hpp"

int main(void)
{
    std::cout << "\n--- Create MateriaSource and learn materias ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Ice());  // should not be stored (only 4 max)

    std::cout << "\n--- Create Character me and equip materias ---" << std::endl;
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice"); // inventory full
    me->equip(tmp); // should be ignored

    std::cout << "\n--- Create Character bob and use materias ---" << std::endl;
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob); // invalid index

    std::cout << "\n--- Test unequip ---" << std::endl;
    me->unequip(1); 
    me->use(1, *bob);

    std::cout << "\n--- Test deep copy of Character ---" << std::endl;
    Character copyMe = *(dynamic_cast<Character*>(me));
    copyMe.use(0, *bob);
    copyMe.use(1, *bob); // nothing (it was unequipped before copy)

    std::cout << "\n--- Test deep copy of MateriaSource ---" << std::endl;
    MateriaSource* copySrc = new MateriaSource(*(dynamic_cast<MateriaSource*>(src)));
    AMateria* tmp2 = copySrc->createMateria("cure");
    if (tmp2)
        std::cout << "Copy source can still create Cure" << std::endl;
    delete tmp2;

    std::cout << "\n--- Clean up ---" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete copySrc;
    
    return (0);
}
