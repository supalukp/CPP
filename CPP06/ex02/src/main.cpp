/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:58:13 by spunyapr          #+#    #+#             */
/*   Updated: 2025/12/05 16:10:30 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    std::srand(std::time(NULL));
    
    Base *a = generate();
    Base &b =  *a;
    
    identify(a);
    identify(b);
    
    delete a;
    return (0);
}
