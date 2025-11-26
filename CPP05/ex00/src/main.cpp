/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:07:25 by spunyapr          #+#    #+#             */
/*   Updated: 2025/11/26 13:27:31 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat a;
    Bureaucrat b("B", 1);
    Bureaucrat c(b);
    Bureaucrat d;
    d = a;
    try
    {
        b.increaseGrade();
        Bureaucrat e("E", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Catch Exception: "<< e.what() << std::endl;
    }

    return (0);
}
