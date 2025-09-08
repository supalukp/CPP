/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:37:23 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 21:59:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void print_point_position(std::string pointName, bool bsp) {
	std::cout << pointName << " is ";
	if (bsp == true)
		std::cout << "inside" << std::endl;
	else
		std::cout << "not inside" << std::endl;
}

int main(void) 
{
	// Triangle point
	Point a(0.0, 0.0);
	Point b(20.0, 0.0);
	Point c(10.0, 30.0);

	// TEST : inside point
	Point insidePoint(10.0, 15.0);
	print_point_position("insidePoint", bsp(a, b, c, insidePoint));
	
	// TEST : outside point
	Point outsidePoint(30.0, 30.0);
	print_point_position("outsidePoint", bsp(a, b, c, outsidePoint));

	// TEST : on edge points
	Point p_on_AB(10.0, 0.0);
	print_point_position("p_on_AB", bsp(a, b, c, p_on_AB));
	
	Point p_on_BC(15.0, 15.0);
	print_point_position("p_on_BC", bsp(a, b, c, p_on_BC));

	Point p_on_AC(5.0, 15.0);
	print_point_position("p_on_AC", bsp(a, b, c, p_on_AC));

	return (0);
}
