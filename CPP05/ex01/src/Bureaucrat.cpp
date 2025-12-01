/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:22 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/01 14:53:32 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor called with name and grade" << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout   << _name << " : " 
                << "Bureaucrat destructor called" << std::endl;
}

std::string const& Bureaucrat::getName(void) const { return (_name); }

int Bureaucrat::getGrade(void) const { return (_grade); }

void Bureaucrat::increaseGrade(void)
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade -= 1;
}
void Bureaucrat::decreaseGrade(void)
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade += 1;
}

std::ostream& operator <<(std::ostream &out, const Bureaucrat& name)
{ 
    out << name.getName() << ", bureaucrat grade " << name.getGrade() << ".";
    return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
        return ;
    }
    
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
}
