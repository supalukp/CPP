/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:24:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/19 16:17:53 by spunyapr         ###   ########.fr       */
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
        Contact _ContactList[8];
        int _Count;
        int _NextIndex;
    
    public:
        PhoneBook ();
        ~ PhoneBook ();
        void addContact(Contact newContact);
        void displayContact();
        bool getIndexInfo();
        int getCount() const ;
};


#endif