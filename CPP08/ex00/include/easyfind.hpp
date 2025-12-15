/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:23:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/15 15:43:34 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

class NotFound : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("Can not find the value inside container");
        }
};


template <typename T>
int easyfind(T &container, int value)
{
    for(typename Container::iterator it = c.begin(); it != c.end(); it++)
    {
        if (*it == value)
            return (value);
    }
    throw NotFound();
}

#endif
