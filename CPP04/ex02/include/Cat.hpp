/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:16:49 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 17:50:05 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* _catBrain;
        
    public:
        Cat(void); // Default constructor
        Cat(const Cat &other); // Default constructor
		Cat& operator=(const Cat& other); // Copy assignment operator
        ~Cat(void); // Destructor

        void makeSound(void) const ;
        Brain* getBrain(void);
        const Brain* getBrain(void) const;
    
};

#endif
