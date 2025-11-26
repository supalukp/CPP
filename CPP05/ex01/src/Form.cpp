/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:25:50 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/26 16:12:09 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) 
    :_name("default"), 
    _signed(false),
    _gradeSign(150),
    _gradeExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, const int gradeSign, const int gradeExecute) 
    :_name(name),
    _signed(false),
    _gradeSign(gradeSign),
    _gradeExecute(gradeExecute)
{
    if (gradeSign < 1)
        throw GradeTooHighException();
    else if (gradeSign > 150)
        throw GradeTooLowException();
    if (gradeExecute < 1)
        throw GradeTooHighException();
    else if (gradeExecute > 150)
        throw GradeTooLowException();
        
    std::cout << "Form constructor called with parameters" << std::endl;
}
Form::Form(const Form &other) 
    : _name(other._name),
    _signed(other._signed),
    _gradeSign(other._gradeSign),
    _gradeExecute(other._gradeExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return (*this);
}

Form::~Form(void)
{
    std::cout   << _name << " : " 
                << "Form destructor called" << std::endl;
}

std::string const& Form::getName(void) const { return (_name); }

bool Form::getIsSigned(void) const { return (_signed); } 

int Form::getGradeSign(void) const { return (_gradeSign); }

int Form::getGradeExecute(void) const { return (_gradeExecute); }

std::ostream& operator<<(std::ostream &out, const Form& name)
{
    out << name.getName()  << "form :"
        << " gradeSign " << name.getGradeSign() 
        << " gradeExecute " << name.getGradeExecute();
        
    if (name.getIsSigned() == true)
        out << " > Form is signed" << std::endl;
    else
        out << " > Form is not signed yet" << std::endl;
    
    return (out);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Form::beSigned(const Bureaucrat &name)
{
    if (name.getGrade() < 1)
        throw GradeTooHighException();
    else if (name.getGrade() > 150)
        throw GradeTooLowException();
    else
        _signed = true;
}
