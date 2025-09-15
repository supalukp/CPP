/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:35:33 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/15 17:51:50 by spunyapr         ###   ########.fr       */
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
        Brain(void); // Default constructor
        Brain(const Brain &other); // Default constructor
        Brain& operator=(const Brain& other); // Copy assignment operator
        ~Brain(void); // Destructor

        const std::string& getIdea (int index) const;
        void setIdea(int index, const std::string& newIdea);
};

#endif
