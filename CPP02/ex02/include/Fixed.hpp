/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:36:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/02 17:28:30 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
  private:
	int _fixed;
	static const int _fractionBit;

  public:
	Fixed();
	Fixed(const int newValue);
	Fixed(const float newValue);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	friend std::ostream& operator<<(std::ostream &out, const Fixed& num);
	~Fixed();
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	bool operator<(const Fixed& other);
	bool operator>(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);

	friend Fixed operator+(Fixed x, Fixed const& y);
	friend Fixed operator-(Fixed x, Fixed const& y);
	friend Fixed operator*(Fixed x, Fixed const& y);
	friend Fixed operator/(Fixed x, Fixed const& y);
};

#endif
