/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:10:58 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 21:57:19 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point 
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other );
		Point& operator=(const Point& other);
		~Point(void);
		
		Fixed const& getX(void) const;
		Fixed const& getY(void) const;
};

#endif