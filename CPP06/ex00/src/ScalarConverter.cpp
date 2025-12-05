/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:42:57 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/05 11:21:46 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void) other;
    return (*this);
}

ScalarConverter::~ScalarConverter(void) { }

bool ScalarConverter::isChar(const std::string &str, size_t len)
{
    if (len == 1 && !isdigit(static_cast<unsigned char>(str[0])))
        return (true);
    if (len == 3 && str[0] == '\'' && str[2] == '\'')
    
        return (true);
    return (false);
}

bool ScalarConverter::isInt(const std::string &str, size_t len)
{
    size_t index = 0;
    
    if (str.empty())
        return false;
    if (str[0] == '-' || str[0] == '+')
        index = 1;
    if (index == len)
        return false;
    while (index < len)
    {
        if (!isdigit(static_cast<unsigned char>(str[index])))
            return (false);
        index++;
    } 
    return (true);
}

bool ScalarConverter::isFloat(const std::string &str, size_t len)
{
    size_t index = 0;
    size_t dot = 0;
    size_t digits = 0;
    
    if (len < 2)
        return (false);
    if (str[len - 1] != 'f')
        return (false);
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    if (str[0] == '+' || str[0] == '-')
        index = 1;
    while (index < len - 1)
    {
        if (str[index] == '.')
            dot++;
        else if (isdigit(static_cast<unsigned char>(str[index])))
            digits++;
        else
            return false;
        index++;
    }
    if (dot != 1 || digits == 0)
        return (false);
    return (true);
}

bool ScalarConverter::isDouble(const std::string &str, size_t len)
{
    size_t index = 0;
    size_t dot = 0;
    size_t digits = 0;
    
    if (len < 1)
        return (false);
    
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
        
    if (str[0] == '+' || str[0] == '-')
        index = 1;
    while (index < len)
    {
        if (str[index] == '.')
            dot++;
        else if (isdigit(static_cast<unsigned char>(str[index])))
            digits++;
        else
            return false;
        index++;
    }
    if (dot != 1 || digits == 0)
        return (false);
    return (true);
}

t_e_literal ScalarConverter::getType(const std::string &str)
{
    size_t len = str.size();
    
    if (isChar(str, len))
        return CHAR;
    else if (isInt(str, len))
        return INT;
    else if (isFloat(str, len))
        return FLOAT;
    else if (isDouble(str, len))
        return DOUBLE;
    else
        return UNKNOWN;
}

void ScalarConverter::toChar(const std::string &str)
{
    char c;
    
    if (str.size() == 3)
        c = str[1];
    else
        c = str[0];
        
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::toInt(const std::string &str)
{
    errno = 0;
    char *end;
    long value = std::strtol(str.c_str(), &end, 10);
    
    if (end == str.c_str() || errno == ERANGE || value > INT_MAX || value < INT_MIN)
    {
        displayUnknown();
        return;
    }
    
    int i = static_cast<int>(value);
    if (i >= 32 && i <= 126)
    {
        char c = static_cast<char>(i);
        std::cout << "char: " << c << std::endl;
    }
    else if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << std::endl;
}

void ScalarConverter::toFloat(const std::string &str)
{
    errno = 0;
    char *end;
    
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::string doubleStr = str.substr(0, str.size() - 1);
        std::cout << "double: " << doubleStr << std::endl;
        return ;
    }
    long double value = std::strtold(str.c_str(), &end);
    if (end == str.c_str() || errno == ERANGE || value > FLT_MAX || value < -FLT_MAX)
    {
        displayUnknown();
        return;
    }
    
    if (value >= 32 && value <= 126)
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << c << std::endl;
    }
    else if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::toDouble(const std::string &str)
{
    errno = 0;
    char *end;
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return ;
    }
    long double value = std::strtold(str.c_str(), &end);
    if (end == str.c_str() || errno == ERANGE || value > DBL_MAX || value < -DBL_MAX)
    {
        displayUnknown();
        return;
    }
    
    if (value >= 32 && value <= 126)
    {
        char c = static_cast<char>(value);
        std::cout << "char: " << c << std::endl;
    }
    else if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    if (value > FLT_MAX || value < -FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::displayUnknown(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}


void ScalarConverter::convert(const std::string &str)
{
    t_e_literal type = getType(str);

    switch (type)
    {
        case CHAR:
            toChar(str);
            break ;
        case INT:
            toInt(str);
            break ;

        case FLOAT:
            toFloat(str);
            break ;

        case DOUBLE:
            toDouble(str);
            break ;
        
        case UNKNOWN:
            displayUnknown();
            break ;
    }
    
}
