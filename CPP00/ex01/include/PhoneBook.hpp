/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 18:24:55 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/21 13:13:05 by spunyapr         ###   ########.fr       */
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
        PhoneBook ( void );
        ~ PhoneBook ( void );
        void addContact(Contact newContact);
        void displayContact( void );
        bool getIndexInfo( void );
        int getCount( void ) const ;
};

#endif
