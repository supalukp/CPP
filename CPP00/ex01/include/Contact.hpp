/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:19:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/21 11:39:02 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact {
    private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
        
    public:
    Contact( void );
    ~ Contact( void );
    bool fillContact( void );
    void displayInfo( void );
    static bool checkAlpha(const std::string& str);
    static bool checkDigit(const std::string& str);
    std::string getFirstName( void ) const ;
    std::string getLastName( void ) const ;
    std::string getNickname( void ) const ;
    std::string getPhoneNumber( void ) const ;
    std::string getDarkSecret( void ) const ;
    bool setFirstName( void ) ;
    bool setLastName( void ) ;
    bool setNickname( void ) ;
    bool setPhoneNumber( void ) ;
    bool setDarkSecret( void ) ;
    
};

bool safeGetLine(std::string& str, std::string prompt);

#endif
