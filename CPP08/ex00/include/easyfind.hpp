/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:23:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/16 10:59:53 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

class NotFound : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Can not find the value inside container");
        }
};

template <typename T>
int easyfind(T &c, int value)
{
    if ((std::find(c.begin(), c.end(), value)) == c.end())
        throw NotFound();
    return (value);
}

#endif
