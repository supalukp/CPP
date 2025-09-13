/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 22:37:46 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/12 17:43:27 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap 
{
    public:
        FragTrap(void);
        FragTrap(const std::string& name);
        FragTrap(const FragTrap &other); // Copy constructor
		FragTrap& operator=(const FragTrap& other);  // Copy assignment operator
		~FragTrap(void);

        void highFivesGuys(void);
};

#endif
