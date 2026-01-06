/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:07:59 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/06 15:59:10 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) { }

RPN::RPN(const RPN &other)
{
    this->_operand = other._operand;    
}

RPN& RPN::operator=(const RPN& other)
{
    if(this != &other)
    {
        this->_operand = other._operand;
    }
    return (*this);
}

RPN::~RPN(void) { }

const char* RPN::NotValidExpression::what() const throw()
{
    return ("Not valid expression");
}

static bool isExpression(char c)
{
    std::string expression = "+-*/";
    for (int i = 0; i < 4; i++)
    {
        if (c == expression[i])
            return (true);
    }
    return (false);
}

int RPN::computeExpression(int right, int left, char expression)
{
    switch (expression)
    {
        case '+':
            return (left + right);
        case '-':
            return (left - right);
        case '*':
            return (left * right);
        case '/':
            return (left / right);
        default:
            throw NotValidExpression();
    }
}

void RPN::evalRPN(const std::string &str)
{
    bool needSpace = false;
    for(unsigned long i = 0; i < str.size(); i++)
    {
        if (std::isdigit(str[i]) && needSpace == false)
        {
            needSpace = true;
            _operand.push(str[i] - '0');
        }
        else if (isExpression(str[i]))
        {
            needSpace = true;
            if (_operand.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return ;
            }
            else
            {
                int right = _operand.top();
                _operand.pop();
                int left = _operand.top();
                _operand.pop();
                if (str[i] == '/' && right == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return ;
                }
                int res = computeExpression(right, left, str[i]);
                _operand.push(res);
            }
        }
        else if (str[i] == ' ')
        {
            needSpace = false;
            continue;
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }
    if (_operand.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return ;
    }
    std::cout << _operand.top() << std::endl;
}
