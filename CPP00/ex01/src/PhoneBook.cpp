/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:24:30 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/19 16:18:50 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include <stdlib.h>

PhoneBook::PhoneBook() {
    _Count = 0;
    _NextIndex = 0;
}

PhoneBook::~PhoneBook () { }

void PhoneBook::addContact(Contact newContact)
{
    this->_ContactList[this->_NextIndex] = newContact;
    this->_NextIndex = (this->_NextIndex + 1) % 8;
    if (this->_Count < 8)
        this->_Count++;
}

static std::string truncateOnlyTen(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

int PhoneBook::getCount(void) const { return (this->_Count); }

bool PhoneBook::getIndexInfo()
{
    std::string input;
    int index;
    
    while (true)
    {
        if (!safeGetLine(input, "Choose index: "))
            return (false);
        index = atoi(input.c_str());
        if (index < 1 || index > _Count)
        {
            std::cout << "Wrong input, try again\n";
            continue;
        }
        else
        {
            std::cout << "\n";
            this->_ContactList[index-1].displayInfo();
            return (true);
        }
    }
}

void PhoneBook::displayContact()
{
    std::string input;
    
    std::cout << "\n";
    std::cout << "-------------------------------------------\n";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name"  << "|"
              << std::setw(10) << "Nickname"   << std::endl;
    for (int i = 0; i < this->_Count; i++)
    {
        std::cout   << std::setw(10) << i+1 << "|" 
                    << std::setw(10) << truncateOnlyTen(this->_ContactList[i].getFirstName()) << "|" 
                    << std::setw(10) << truncateOnlyTen(this->_ContactList[i].getLastName()) << "|" 
                    << std::setw(10) << truncateOnlyTen(this->_ContactList[i].getNickname()) << std::endl;
    }
    std::cout << "-------------------------------------------\n";
}
