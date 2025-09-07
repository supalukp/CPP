/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:16:49 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/07 23:09:11 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
    private:
        Brain* _catBrain;
        
    public:
        Cat(void);
        Cat(const Cat &other);
        Cat& operator=(const Cat& other);
        ~Cat(void);

        void makeSound( void ) const ;
    
};

#endif
