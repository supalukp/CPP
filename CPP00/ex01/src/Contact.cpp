/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:19:41 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/18 16:09:45 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

bool Contact::checkAlpha(const std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isalpha(str[i]))
			return (false);
	}
	return (true);
}

bool Contact::checkDigit(const std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void Contact::fillContact()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstname);
	while (!checkAlpha(firstname))
	{
		std::cout << "Invalid input. Please enter letters only: ";
		std::getline(std::cin, firstname);
	}
	std::cout << "Last name: ";
	std::getline(std::cin, lastname);
	while (!checkAlpha(lastname))
	{
		std::cout << "Invalid input. Please enter letters only: ";
		std::getline(std::cin, lastname);
	}
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	while (!checkAlpha(nickname))
	{
		std::cout << "Invalid input. Please enter letters only: ";
		std::getline(std::cin, nickname);
	}
	std::cout << "Phone number: ";
	std::getline(std::cin, phonenumber);
	while (!checkDigit(phonenumber))
	{
		std::cout << "Invalid input. Please enter numbers only: ";
		std::getline(std::cin, phonenumber);
	}
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
}

void Contact::displayInfo()
{
	std::cout << "First Name: " << getFirstname() << std::endl;
    std::cout << "Last Name: " << getLastName() << std::endl;
    std::cout << "Nickame: " << getNickname() << std::endl;
    std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << getDarkSecret() << std::endl;  
}

std::string Contact::getFirstname() const
{
	return (firstname);
}

std::string Contact::getLastName() const
{
	return (lastname);
}

std::string Contact::getNickname() const
{
	return (nickname);
}

std::string Contact::getPhoneNumber() const
{
	return (phonenumber);
}

std::string Contact::getDarkSecret() const
{
	return (secret);
}