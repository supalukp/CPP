/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:55:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/18 12:11:44 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iostream>


void displayOption()
{
    std::cout << "\n";
    std::cout << "===========================================\n";
    std::cout << "             PHONE CONTACT BOOK         \n";
    std::cout << "===========================================\n";
    std::cout << "Choose your option:\n";
    std::cout << "           ADD    - Add a new contact\n";
    std::cout << "           SEARCH - Find a contact\n";
    std::cout << "           EXIT   - Quit program\n";
    std::cout << "-------------------------------------------\n";
    std::cout << "Enter your choice: ";
}

int main(int ac, char *av[])
{
    (void) av;
    if (ac != 1)
        return (0);
    PhoneBook pb;
    while (1)
    {
        std::string option;
        displayOption();
        std::getline(std::cin, option);
        if (option == "ADD")
        {
            Contact newContact;
            newContact.fillContact();
            pb.addContact(newContact);
        }
        else if (option == "SEARCH")
            pb.displayContact();
        else if (option == "EXIT")
            break;
        else
            std::cout << "Wrong option, Try agian" << std::endl;
    }
    return (0);
}