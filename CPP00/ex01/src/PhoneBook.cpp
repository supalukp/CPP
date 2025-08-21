/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:24:30 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/21 11:40:10 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include <stdlib.h>

PhoneBook::PhoneBook( void ) 
{
    _count = 0;
    _index = 0;
}

PhoneBook::~PhoneBook ( void ) { }

void PhoneBook::addContact(Contact newContact)
{
    _contactList[_index] = newContact;
    _index = (_index + 1) % 8;
    if (_count < 8)
        _count++;
}

static std::string truncateOnlyTen(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

int PhoneBook::getCount( void ) const { return (_count); }

bool PhoneBook::getIndexInfo( void )
{
    std::string input;
    int index;
    
    while (true)
    {
        if (!safeGetLine(input, "Choose index: "))
            return (false);
        index = atoi(input.c_str());
        if (index < 1 || index > _count)
        {
            std::cout << "Wrong input, try again\n";
            continue;
        }
        else
        {
            std::cout << "\n";
            _contactList[index-1].displayInfo();
            return (true);
        }
    }
}

void PhoneBook::displayContact( void )
{
    std::string input;
    
    std::cout << "\n";
    std::cout << "-------------------------------------------\n";
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name"  << "|"
              << std::setw(10) << "Nickname"   << std::endl;
    for (int i = 0; i < _count; i++)
    {
        std::cout   << std::setw(10) << i+1 << "|" 
                    << std::setw(10) << truncateOnlyTen(_contactList[i].getFirstName()) << "|" 
                    << std::setw(10) << truncateOnlyTen(_contactList[i].getLastName()) << "|" 
                    << std::setw(10) << truncateOnlyTen(_contactList[i].getNickname()) << std::endl;
    }
    std::cout << "-------------------------------------------\n";
}
