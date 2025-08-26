/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:17:42 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/26 22:35:32 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) 
{ 
	funct[0] = &Harl::debug;
    funct[1] = &Harl::info;
    funct[2] = &Harl::warning;
    funct[3] = &Harl::error;

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

Harl::~Harl(void) { }

void Harl::debug(void)
{
	std::cout 
		<< "[ DEBUG ]" << std::endl 
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout 
		<< "[ INFO ]" << std::endl 
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout 
		<< "[ WARNING ]" << std::endl 
		<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout 
		<< "[ ERROR ]" << std::endl 
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{	
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*funct[i])();
			return ;
		}
	}
}
