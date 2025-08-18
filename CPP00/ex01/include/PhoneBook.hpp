/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:24:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/18 12:42:39 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"


class PhoneBook {
    private:
    Contact ContactList[8];
    int count;
    int nextIndex;
    
    public:
    PhoneBook ();
    void addContact(Contact newContact);
    void displayContact();
};

std::string truncateOnlyTen(std::string str);

#endif