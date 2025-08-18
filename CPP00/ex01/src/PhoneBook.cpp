/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:24:30 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/18 12:17:50 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include <stdlib.h>

PhoneBook::PhoneBook() {
    count = 0;
    nextIndex = 0;
}

void PhoneBook::addContact(Contact newContact)
{
    ContactList[nextIndex] = newContact;
    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        count++;
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
    for (int i = 0; i < count; i++)
    {
        std::cout   << std::setw(10) << i+1 << "|" 
                    << std::setw(10) << truncateOnlyTen(ContactList[i].getFirstname()) << "|" 
                    << std::setw(10) << truncateOnlyTen(ContactList[i].getLastName()) << "|" 
                    << std::setw(10) << truncateOnlyTen(ContactList[i].getNickname()) << std::endl;
    }
    std::cout << "-------------------------------------------\n";
    std::cout << "Choose index: ";
    std::getline(std::cin, input);
    int index = atoi(input.c_str());
    while (index < 1 || index > count)
    {
        std::cout << "Wrong option, Choose again\n";
        std::getline(std::cin, input);
        index = atoi(input.c_str());
    }
    std::cout << "\n";
    ContactList[index-1].displayInfo();
}
