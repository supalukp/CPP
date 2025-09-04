/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:11:23 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/04 15:58:29 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsp.hpp"

static Fixed area( Point const& a, Point const& b, Point const& c ) 
{
	Fixed partA = a.getX() * (b.getY() - c.getY());
	Fixed partB = b.getX() * (c.getY() - a.getY());
	Fixed partC = c.getX() * (a.getY() - b.getY());
	
	Fixed total = partA + partB + partC;
	
	if (total < Fixed(0))
		return (total * Fixed(-1));
	return (total);
}

bool bsp( Point const& a, Point const& b, Point const& c, Point const& point )
{
	Fixed A = area(a, b, c);
	Fixed A1 = area(point, b, c);
	Fixed A2 = area(a, point, c);
	Fixed A3 = area(a, b, point);

	if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0))
		return (false);
		
	return (A == A1 + A2 + A3);
}
