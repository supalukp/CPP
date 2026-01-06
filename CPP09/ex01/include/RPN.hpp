/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:07:55 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/06 15:42:16 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <exception>

class RPN
{
    private:
        std::stack<int> _operand;
        
    public:
        RPN(void);
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);
        ~RPN(void);
        
        class NotValidExpression : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        int computeExpression(int right, int left, char expression);
        void evalRPN(const std::string &str);
};

#endif