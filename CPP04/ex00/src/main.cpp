/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:27:49 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 14:27:51 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "\n****** Correct Animals ******" << std::endl;
    
    std::cout << "\n--- Animal Test ---" << std::endl;
    const Animal* ani = new Animal();
    std::cout << "Type is " << ani->getType() << std::endl;
    ani->makeSound();
    delete ani;
    
    std::cout << "\n--- Dog Test ---" << std::endl;
    const Animal* j = new Dog();
    std::cout << "Type is " << j->getType() << std::endl;
    j->makeSound();
    delete j;
  
    std::cout << "\n--- Cat Test ---" << std::endl;
    const Animal* i = new Cat();
    std::cout << "Type is " << i->getType() << std::endl;
    i->makeSound();
    delete i;


    std::cout << "\n****** Wrong Animals ******\n" << std::endl;
    const WrongAnimal* wani = new WrongAnimal();
    const WrongAnimal* wcat = new WrongCat();

    std::cout << "Type is " << wcat->getType() << std::endl;
    std::cout << "Type is " << wani->getType() << std::endl;
    wcat->makeSound();
    wani->makeSound();

    delete wani;
    delete wcat;

    std::cout << "\n--- Direct WrongCat ---\n" << std::endl;
    WrongCat directWrong;
    directWrong.makeSound();

    return (0);
}
