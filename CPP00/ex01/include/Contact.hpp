/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:19:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/19 15:50:32 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact {
    private:
    std::string _FirstName;
    std::string _LastName;
    std::string _Nickname;
    std::string _PhoneNumber;
    std::string _DarkestSecret;
        
    public:
    Contact();
    ~ Contact();
    bool fillContact();
    void displayInfo();
    static bool checkAlpha(const std::string& str);
    static bool checkDigit(const std::string& str);
    std::string getFirstName() const ;
    std::string getLastName() const ;
    std::string getNickname() const ;
    std::string getPhoneNumber() const ;
    std::string getDarkSecret() const ;
    bool setFirstName() ;
    bool setLastName() ;
    bool setNickname() ;
    bool setPhoneNumber() ;
    bool setDarkSecret() ;
    
    
};

bool safeGetLine(std::string& str, std::string prompt);

#endif
