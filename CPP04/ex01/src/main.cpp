/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:27:49 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 21:32:11 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void) {
    std::cout << "\n\n==============================" << std::endl;
    std::cout << "        TEST FOR CAT          " << std::endl;
    std::cout << "==============================\n" << std::endl;
    std::cout << "\n--- Cat Creation ---" << std::endl;
    Cat cat1;
    cat1.getBrain()->setIdea(0, "Eat fish");
    cat1.getBrain()->setIdea(1, "Sleep");

    std::cout << "cat1 ideas: " 
              << cat1.getBrain()->getIdea(0) << ", "
              << cat1.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Copy Constructor ---" << std::endl;
    Cat cat2(cat1);
    std::cout << "cat2 ideas: " 
              << cat2.getBrain()->getIdea(0) << ", "
              << cat2.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Assignment Operator ---" << std::endl;
    Cat cat3;
    cat3 = cat1; 
    std::cout << "cat3 ideas: " 
              << cat3.getBrain()->getIdea(0) << ", "
              << cat3.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Modify Original ---" << std::endl;
    cat1.getBrain()->setIdea(0, "Play");
    cat1.getBrain()->setIdea(1, "Run");

    std::cout << "cat1 ideas: " 
              << cat1.getBrain()->getIdea(0) << ", "
              << cat1.getBrain()->getIdea(1) << std::endl;
    std::cout << "cat2 ideas: " 
              << cat2.getBrain()->getIdea(0) << ", "
              << cat2.getBrain()->getIdea(1) << std::endl;
    std::cout << "cat3 ideas: " 
              << cat3.getBrain()->getIdea(0) << ", "
              << cat3.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n\n==============================" << std::endl;
    std::cout << "        TEST FOR DOG          " << std::endl;
    std::cout << "==============================\n" << std::endl;
    std::cout << "\n--- Dog Creation ---" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Bark");
    dog1.getBrain()->setIdea(1, "Eat");

    std::cout << "dog1 ideas: " 
            << dog1.getBrain()->getIdea(0) << ", "
            << dog1.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Copy Constructor ---" << std::endl;
    Dog dog2(dog1);
    std::cout << "dog2 ideas: " 
            << dog2.getBrain()->getIdea(0) << ", "
            << dog2.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Assignment Operator ---" << std::endl;
    Dog dog3;
    dog3 = dog1;
    std::cout << "dog3 ideas: " 
            << dog3.getBrain()->getIdea(0) << ", "
            << dog3.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Modify Original ---" << std::endl;
    dog1.getBrain()->setIdea(0, "Run");
    dog1.getBrain()->setIdea(1, "Play");

    std::cout << "dog1 ideas: " 
            << dog1.getBrain()->getIdea(0) << ", "
            << dog1.getBrain()->getIdea(1) << std::endl;
    std::cout << "dog2 ideas: " 
            << dog2.getBrain()->getIdea(0) << ", "
            << dog2.getBrain()->getIdea(1) << std::endl;
    std::cout << "dog3 ideas: " 
            << dog3.getBrain()->getIdea(0) << ", "
            << dog3.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n\n==============================" << std::endl;
    std::cout << "     TEST FOR Polymorphism    " << std::endl;
    std::cout << "==============================\n" << std::endl;
    
    std::cout << "\n--- Allocate Dog & Cat ---" << std::endl;
    Animal* animals[10];
    for (int i = 0; i < 10; i++)
    {
        if (i < 10/2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << "\n--- Make sound Test ---" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }
    
    std::cout << "\n--- Delete animals ---" << std::endl;
    for (int i = 0; i < 10; i++)
        delete animals[i];

    return (0);
}

