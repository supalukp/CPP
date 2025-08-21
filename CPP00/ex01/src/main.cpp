/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:55:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/21 11:19:45 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"
#include <iostream>

static void displayOption()
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
}

int main(int ac, char *av[])
{
    (void) av;
    if (ac != 1)
        return (0);
    PhoneBook pb;
    std::string option;
    while (1)
    {
        displayOption();
        if (!safeGetLine(option, "Enter your choice: "))
            break;
        if (option == "ADD")
        {
            Contact newContact;
            if (newContact.fillContact() == false)
                break;
            pb.addContact(newContact);
        }
        else if (option == "SEARCH")
        {
            if (pb.getCount() > 0)
            {
                pb.displayContact();
                if (pb.getIndexInfo() == false)
                    break;
            }
        }
        else if (option == "EXIT")
            break;
        else
            std::cout << "Wrong option, Try agian" << std::endl;
    }
    return (0);
}
