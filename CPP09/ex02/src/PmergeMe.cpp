/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:07 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/09 18:05:28 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { }

// PmergeMe::PmergeMe(const PmergeMe& other) 
// {
    
// }

// PmergeMe& PmergeMe::operator=(const PmergeMe& other)
// {
    
// }

PmergeMe::~PmergeMe(void) { }

void PmergeMe::addValueToMain(int value)
{
    _v_main.push_back(value);
}

void PmergeMe::printMain()
{
    for (std::vector<int>::iterator it = _v_main.begin(); it != _v_main.end(); ++it)
            std::cout << *it << " ";
}

/**
 * Take a sequence and return the sorted winner chain,
 * while preserving pair relationships
 * 
 * 1. pair elements and record winner/loser
 * 2 .Keep compare winner until size of 1
 * 3. Recursive back to get sort winner list
 * 4. Return Winner list
 */


std::vector<int> PmergeMe::getWinnerList(std::vector<int> list)
{
    std::vector<int> winner;
    std::vector<int> loser;
    
    if (list.size() == 1)
        return (list);
    for (std::vector<int>::iterator it = list.begin(); it != list.end(); it += 2)
    {
        if (*it > *(it+1))
        {
            winner.push_back(*it);
            loser.push_back(*(it+1));
        }
        else
        {
            winner.push_back(*(it+1));
            loser.push_back(*it);
        }
    }
    std::vector<int> res = getWinnerList(winner);
    return (res);
}
 
