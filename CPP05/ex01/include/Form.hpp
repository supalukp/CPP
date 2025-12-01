/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:25:40 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/01 13:15:10 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
    
    public:
        Form(void);
        Form(std::string name, const int gradeSign, const int gradeExecute); 
        Form(const Form &other);
        Form& operator=(const Form& other);
        ~Form(void);
        
        // Getters
        std::string const& getName(void) const;
        bool getIsSigned(void) const; 
        int getGradeSign(void) const;
        int getGradeExecute(void) const;
        
        void beSigned(const Bureaucrat &bureaucrat);

        // Exception
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

};

// Overload operator (<<)
std::ostream& operator<<(std::ostream &out, const Form& name);

#endif
