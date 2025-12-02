/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:45:14 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/02 14:28:56 by spunyapr         ###   ########.fr       */
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
    private:
        AForm* makeShrubbery(std::string target);
        AForm* makeRobotomy(std::string target);
        AForm* makePresidential(std::string target);
        typedef AForm* (Intern::*ptrFunction)(std::string target);
        ptrFunction funct[3];
        std::string validName[3];
        
    public:
        Intern(void);
        Intern(const Intern &other);
        Intern& operator=(const Intern& other);
        ~Intern(void);
        
        AForm *makeForm(std::string const formName, std::string const formTarget);
};

#endif
