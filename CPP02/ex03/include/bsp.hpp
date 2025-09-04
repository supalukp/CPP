/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:54:54 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/04 15:28:35 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSP_HPP
# define BSP_HPP

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const& a, Point const& b, Point const& c, Point const& point );

#endif