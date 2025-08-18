/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:19:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/18 12:05:07 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact {
    private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string phonenumber;
    std::string secret;
        
    public:
    Contact () {}
    void fillContact();
    void displayInfo();
    bool checkAlpha(const std::string& str);
    bool checkDigit(const std::string& str);
    std::string getFirstname() const ;
    std::string getLastName() const ;
    std::string getNickname() const ;
    std::string getPhoneNumber() const ;
    std::string getDarkSecret() const ;
    
};


#endif