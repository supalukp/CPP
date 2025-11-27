/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:43:35 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/27 18:21:01 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_FORM_HPP
#define A_FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExecute;
    
    public:
        AForm(void);
        AForm(std::string name, const int gradeSign, const int gradeExecute); 
        AForm(const AForm &other);
        AForm& operator=(const AForm& other);
        ~AForm(void);
    
        std::string const& getName(void) const;
        bool getIsSigned(void) const; 
        int getGradeSign(void) const;
        int getGradeExecute(void) const;

        void beSigned(const Bureaucrat &bureaucrat);
        void execute(Bureaucrat const & executor) const;
        virtual void executeAction(void) const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream &out, const AForm& name);

#endif
