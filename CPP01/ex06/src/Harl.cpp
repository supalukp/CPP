/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:17:42 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/22 21:45:19 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) { }

Harl::~Harl(void) { }

void Harl::debug(void)
{
	std::cout 
		<< "[ DEBUG ]" << std::endl 
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
	std::cout 
		<< "[ INFO ]" << std::endl 
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
	std::cout 
		<< "[ WARNING ]" << std::endl 
		<< "I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout 
		<< "[ ERROR ]" << std::endl 
		<< "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	
	while (i < 4)
	{
		if (levels[i] == level)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			debug();
			// fall through
		case 1: 
			info();
			// fall through
		case 2:
			warning();
			// fall through
		case 3: 
			error();
			break;
		default: {
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
	}
}
