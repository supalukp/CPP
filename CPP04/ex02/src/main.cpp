/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:27:49 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/17 21:30:21 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void) 
{
        // Animal a; //  This should not compile because Animal is abstract class
           
    std::cout << "\n--- Creating Dog and Cat ---" << std::endl;
    std::cout << "** Construction: Base first, then members, then derived **" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "\n--- Testing sounds ---" << std::endl;
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n--- Getting types ---" << std::endl;
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\n--- Clean up ---" << std::endl;
    std::cout << "** Destruction: Derived first, then members, then base **" << std::endl;
    delete dog;
    delete cat;

    return (0);
}
