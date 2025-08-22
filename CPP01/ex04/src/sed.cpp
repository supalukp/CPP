/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:05:35 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/22 12:54:26 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void ft_sed( std::string& origin, std::string const find, std::string const replace)
{
	std::string result;
	for (size_t i = 0; i < origin.length(); i++)
	{
		if (origin.substr(i, find.length()) == find)
		{
			result += replace;
			i += find.length() - 1;
		}
		else
			result += origin[i];
	}
	origin =  result;
}
