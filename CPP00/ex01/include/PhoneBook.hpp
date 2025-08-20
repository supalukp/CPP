/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:24:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/20 16:32:43 by spunyapr         ###   ########.fr       */
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
        Contact _contactList[8];
        int _count;
        int _index;
    
    public:
        PhoneBook ();
        ~ PhoneBook ();
        void addContact(Contact newContact);
        void displayContact();
        bool getIndexInfo();
        int getCount() const ;
};


#endif