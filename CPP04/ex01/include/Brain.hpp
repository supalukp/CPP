/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:09:35 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/07 12:29:53 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain 
{
    private:
        std::string _ideas[100];

    public:
        Brain(void);
        Brain(const Brain &other);
        Brain& operator=(const Brain& other);
        ~Brain( void );
    
};

#endif
