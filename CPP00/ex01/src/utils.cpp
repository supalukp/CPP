/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 10:03:28 by spunyapr          #+#    #+#             */
/*   Updated: 2025/08/18 11:18:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string truncateOnlyTen(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}
