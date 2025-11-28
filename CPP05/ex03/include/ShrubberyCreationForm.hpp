/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:47:56 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/28 09:55:30 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target); 
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm(void);
        
        void executeAction(void) const;
};

#endif
