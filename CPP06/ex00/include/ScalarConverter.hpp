/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:42:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/04 21:42:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include "ConvertUtils.hpp"
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <climits>
#include <cfloat>

class ScalarConverter
{
    private:
        static t_e_literal getType(const std::string &str);
        
        static bool isChar(const std::string &str);
        static bool isInt(const std::string &str);
        static bool isFloat(const std::string &str);
        static bool isDouble(const std::string &str);

        static void toChar(const std::string &str);
        static void toInt(const std::string &str);
        static void toFloat(const std::string &str);
        static void toDouble(const std::string &str);
        static void displayUnknown(void);
        
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter(void);
        
    public:
        static void convert(const std::string &str);
};

#endif
