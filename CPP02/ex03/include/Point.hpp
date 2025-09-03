/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:10:58 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/03 17:39:22 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point 
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point( void );
		Point( float const x, float const y );
		Point( const Point &other );
		Point& operator=( const Point& other );
		~Point( void );
};

#endif