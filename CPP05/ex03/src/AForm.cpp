/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:43:26 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/02 11:15:14 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) 
    :_name("default"), 
    _signed(false),
    _gradeSign(150),
    _gradeExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, const int gradeSign, const int gradeExecute) 
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
        
    std::cout << "AForm constructor called with parameters" << std::endl;
}
AForm::AForm(const AForm &other) 
    : _name(other._name),
    _signed(other._signed),
    _gradeSign(other._gradeSign),
    _gradeExecute(other._gradeExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_signed = other._signed;
	}
	return (*this);
}

AForm::~AForm(void)
{
    std::cout   << _name << " : " 
                << "AForm destructor called" << std::endl;
}

std::string const& AForm::getName(void) const { return (_name); }

bool AForm::getIsSigned(void) const { return (_signed); } 

int AForm::getGradeSign(void) const { return (_gradeSign); }

int AForm::getGradeExecute(void) const { return (_gradeExecute); }

std::ostream& operator<<(std::ostream &out, const AForm& name)
{
    out << name.getName()  << "form :"
        << " gradeSign " << name.getGradeSign() 
        << " gradeExecute " << name.getGradeExecute();
        
    if (name.getIsSigned() == true)
        out << " > " << name.getName() << " is signed";
    else
        out << " > " << name.getName() << " is not signed yet";
    
    return (out);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getGradeSign())
        throw GradeTooLowException();
    else
        _signed = true;
}

const char* AForm::FormNotSignException::what() const throw()
{
    return ("Form is not signed yet");
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (_signed == false)
        throw FormNotSignException();
    if (executor.getGrade() > _gradeExecute)
        throw GradeTooLowException();
    
    executeAction();
}
