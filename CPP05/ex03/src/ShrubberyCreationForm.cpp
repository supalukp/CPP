/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:56:57 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/28 15:03:27 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called with name and grade" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout   << _target << " : " 
                << "ShrubberyCreationForm destructor called" << std::endl;
}

static void writeAsciiTree(std::ofstream &outfile)
{
    outfile << "      /\\\n"
            << "     /**\\\n"
            << "    /****\\\n"
            << "   /******\\\n"
            << "     ||\n"
            << "     ||\n";
}

void ShrubberyCreationForm::executeAction(void) const
{
    // Create a file <target>_shrubbery in the working directory and writes ASCII trees inside it
    // write ASCII tree in contents
    std::ofstream outfile;
    std::string outfileName;
    std::string contents;

    outfileName = _target + "_shrubbery";
    outfile.open(outfileName.c_str());
    if (!outfile.is_open()) 
    {
        std::cerr << "Error opening outfile\n";
        return ;
    }
    writeAsciiTree(outfile);
    if (outfile.fail()) 
    {
        std::cerr << "Error writing to output file\n";
        return ;
    }
    outfile.close();
}
