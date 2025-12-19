/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 09:23:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/19 09:24:44 by spunyapr         ###   ########.fr       */
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
typename T::iterator easyfind(T &c, int value)
{
    typename T::iterator it = std::find(c.begin(), c.end(), value);
    if (it == c.end())
        throw NotFound();
    return (it);
}

#endif
