/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:19 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/01 15:27:08 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat 
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade); 
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat(void);
        
        std::string const& getName(void) const;
        int getGrade(void) const;
        void increaseGrade(void);
        void decreaseGrade(void);

        void signForm(AForm &form);
        
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
         
        void executeForm(AForm const & form) const;
};
    
std::ostream& operator <<(std::ostream &out, const Bureaucrat& name);

#endif
