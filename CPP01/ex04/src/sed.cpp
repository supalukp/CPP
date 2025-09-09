/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:05:35 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 16:54:25 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void ft_sed( std::string& origin, std::string const find, std::string const replace)
{
	size_t index = 0;
	
    while ((index = origin.find(find, index)) != std::string::npos)
	{
		origin.erase(index, find.length());
		origin.insert(index, replace);
		index += replace.length();
	}
}
