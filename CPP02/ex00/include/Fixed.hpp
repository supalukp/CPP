/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:36:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/08 21:03:40 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
	int _fixed;
	static const int _fractionBit;

  public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed& other);
	~Fixed(void);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
