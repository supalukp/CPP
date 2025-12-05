/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:42:53 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/05 11:40:59 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <climits>
#include <cfloat>

typedef enum e_literal
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    UNKNOWN
    
} t_e_literal;

class ScalarConverter
{
    private:
        static t_e_literal getType(const std::string &str);
        
        static bool isChar(const std::string &str, size_t len);
        static bool isInt(const std::string &str, size_t len);
        static bool isFloat(const std::string &str, size_t len);
        static bool isDouble(const std::string &str, size_t len);

        static void toChar(const std::string &str);
        static void toInt(const std::string &str);
        static void toFloat(const std::string &str);
        static void toDouble(const std::string &str);
        static void displayUnknown(void);
        static void displayChar(int i);
        static void displaySpecial(const std::string &str);
        
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter(void);
        
    public:
        static void convert(const std::string &str);
};

#endif
