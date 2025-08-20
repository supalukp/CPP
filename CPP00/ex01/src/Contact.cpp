/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 23:19:41 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/20 16:32:19 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"
#include "../include/PhoneBook.hpp"

Contact::Contact() {}
Contact::~ Contact() {}

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

bool Contact::fillContact()
{
	if (this->setFirstName() == false)
		return (false);
	if (this->setLastName() == false)
		return (false);
	if (this->setNickname() == false)
		return (false);
	if (this->setPhoneNumber() == false)
		return (false);
	if (this->setDarkSecret() == false)
		return (false);
	return (true);
}

void Contact::displayInfo()
{
	std::cout << "First Name: " << this->getFirstName() << std::endl;
    std::cout << "Last Name: " << this->getLastName() << std::endl;
    std::cout << "Nickname: " << this->getNickname() << std::endl;
    std::cout << "Phone Number: " << this->getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->getDarkSecret() << std::endl;  
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

bool Contact::setFirstName() 
{
	return (getlineCheckCondition(this->_firstName, "First name: ", Contact::checkAlpha, "letter"));
}
	
bool Contact::setLastName()
{
	return (getlineCheckCondition(this->_lastName, "Last name: ", Contact::checkAlpha, "letter"));
}
bool Contact::setNickname()
{
	return (getlineCheckCondition(this->_nickname, "Nickname: ", Contact::checkAlpha, "letter"));
}
bool Contact::setPhoneNumber()
{
	return (getlineCheckCondition(this->_phoneNumber, "Phone number: ", Contact::checkDigit, "number"));
}
bool Contact::setDarkSecret()
{
	return (safeGetLine( this->_darkestSecret, "Darkest secret: "));
}

std::string Contact::getFirstName() const { return (this->_firstName); }

std::string Contact::getLastName() const { return (this->_lastName); }

std::string Contact::getNickname() const { return (this->_nickname); }

std::string Contact::getPhoneNumber() const { return (this->_phoneNumber); }

std::string Contact::getDarkSecret() const { return (this->_darkestSecret); }
