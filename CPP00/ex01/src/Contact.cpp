/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:19:41 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/21 11:39:38 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

Contact::Contact( void ) {}
Contact::~ Contact( void ) {}

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

bool Contact::fillContact( void )
{
	if (setFirstName() == false)
		return (false);
	if (setLastName() == false)
		return (false);
	if (setNickname() == false)
		return (false);
	if (setPhoneNumber() == false)
		return (false);
	if (setDarkSecret() == false)
		return (false);
	return (true);
}

void Contact::displayInfo( void )
{
	std::cout << "First Name: " << getFirstName() << std::endl;
    std::cout << "Last Name: " << getLastName() << std::endl;
    std::cout << "Nickname: " << getNickname() << std::endl;
    std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << getDarkSecret() << std::endl;  
}

bool safeGetLine(std::string& str, std::string prompt)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, str))
		{
			std::cout << "\n\n**************EOF Exit Program*************" << std::endl;
			return (false);
		}
		if (str.empty())
		{
			std::cout << "Empty input, try again" << std::endl;
			continue;
		}
		return (true);
	}
}

static bool getlineCheckCondition(std::string& str, std::string prompt, bool (*f)(const std::string&), std::string accept)
{
	while (true)
	{
		if (!safeGetLine(str, prompt))
			return (false);
		if (f(str))
			return (true);
		std::cout << "Invalid input. Please enter " << accept << " only\n";
	}
}

bool Contact::setFirstName( void ) 
{
	return (getlineCheckCondition(_firstName, "First name: ", Contact::checkAlpha, "letter"));
}
	
bool Contact::setLastName( void )
{
	return (getlineCheckCondition(_lastName, "Last name: ", Contact::checkAlpha, "letter"));
}
bool Contact::setNickname( void )
{
	return (getlineCheckCondition(_nickname, "Nickname: ", Contact::checkAlpha, "letter"));
}
bool Contact::setPhoneNumber( void )
{
	return (getlineCheckCondition(_phoneNumber, "Phone number: ", Contact::checkDigit, "number"));
}
bool Contact::setDarkSecret( void )
{
	return (safeGetLine(_darkestSecret, "Darkest secret: "));
}

std::string Contact::getFirstName( void ) const { return (_firstName); }

std::string Contact::getLastName( void ) const { return (_lastName); }

std::string Contact::getNickname( void ) const { return (_nickname); }

std::string Contact::getPhoneNumber( void ) const { return (_phoneNumber); }

std::string Contact::getDarkSecret( void ) const { return (_darkestSecret); }
