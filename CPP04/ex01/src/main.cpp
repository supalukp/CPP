/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:27:49 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 14:02:14 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    // // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound();
    // j->makeSound();
    // // meta->makeSound();

    // delete j;
    // delete i;


    // const WrongAnimal* a = new WrongCat();
    // std::cout << a->getType() << " " << std::endl;
    // a->makeSound();
    
    // delete a;

   
    Animal *j[10];
    
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            j[i] = new Dog();
        else
            j[i] = new Cat();
    }
    
    for (int i = 0; i < 10; i++)
        delete j[i];

    return 0;
}