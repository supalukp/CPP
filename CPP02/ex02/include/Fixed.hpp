/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:36:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 21:46:36 by spunyapr         ###   ########.fr       */
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
	Fixed(void);
	Fixed(const int newValue);
	Fixed(const float newValue);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat(void) const;
	int		toInt(void) const;
	
	bool operator<(const Fixed& other) const;
	bool operator>(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed operator++(void); 
	Fixed operator++(int); 
	Fixed operator--(void);
	Fixed operator--(int); 
	
	static Fixed& min(Fixed& x, Fixed& y);
	static Fixed const& min(Fixed const& x, Fixed const& y);
	static Fixed& max(Fixed& x, Fixed& y);
	static Fixed const& max(Fixed const& x, Fixed const& y);
	
};

std::ostream& operator<<(std::ostream &out, const Fixed& num);

#endif
