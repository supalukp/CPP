/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:45:14 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/02 11:28:48 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Intern
{
    public:
        Intern(void);
        Intern(const Intern &other);
        Intern& operator=(const Intern& other);
        ~Intern(void);
        
        class nameNotValid : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        AForm *makeForm(std::string const &formName, std::string const &formTarget);
};

#endif
