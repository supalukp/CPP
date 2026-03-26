/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:07 by spunyapr          #+#    #+#             */
/*   Updated: 2026/03/26 15:31:45 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _v_leftover(false), _v_left_value(0) {
}

// PmergeMe::PmergeMe(const PmergeMe& other) 
// {
    
// }

// PmergeMe& PmergeMe::operator=(const PmergeMe& other)
// {
    
// }

PmergeMe::~PmergeMe(void) { }

void PmergeMe::addValueToMain(int value)
{
    _v_input.push_back(value);
}

void PmergeMe::printMain()
{
    std::cout << "original: ";
    for (std::vector<int>::iterator it = _v_input.begin(); it != _v_input.end(); ++it)
            std::cout << *it << " ";
    std::cout << std::endl;
}

void printVector(const std::vector<int> list)
{
    for (std::vector<int>::const_iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printData(void)
{
    std::cout << "smaller: ";
    for (std::vector<std::pair<int, int> >::iterator it = _v_pairs.begin(); it != _v_pairs.end(); it++)
    {
        std::cout << it->first << " ";
    }
    std::cout << std::endl;

    std::cout << "larger: ";
    for (std::vector<std::pair<int, int> >::iterator it = _v_pairs.begin(); it != _v_pairs.end(); it++)
    {
        std::cout << it->second << " ";
    }
    std::cout << std::endl;
    
    if (_v_leftover == true)
        std::cout << "_v_leftover: " << _v_left_value << std::endl;;
}

/**
 * Take a sequence and return the sorted winner chain,
 * while preserving pair relationships
 * 
 * 1. pair elements and record winner/smaller
 * 2 .Keep compare winner until size of 1
 * 3. Recursive back to get sort winner list
 * 4. Return Winner list
 */

void PmergeMe::orderPair(void)
{
    if (_v_input.size() % 2 == 1)
    {
        _v_leftover = true;
        _v_left_value = _v_input.back();
    }
    
    for (std::vector<int>::iterator it = _v_input.begin(); it != _v_input.end() && it + 1 != _v_input.end(); it += 2)
    {
        if (*it > *(it+1))
            _v_pairs.push_back(std::make_pair(*(it + 1), *it));
        else
            _v_pairs.push_back(std::make_pair(*it, *(it + 1)));
    }

    printData();

    // for (std::vector<std::pair<int,int> >::iterator itp = _v_pairs.begin(); itp != _v_pairs.end() && itp + 1 != _v_pairs.end(); itp += 2)
    // {
    //     if (itp->second > (itp+1)->second)
    //     {
    //         std::pair<int,int> tmp = *itp;
    //         *itp = *(itp + 1);
    //         *(itp + 1) = tmp;
    //     }
    // }
    std::cout << "list now1: ";
    for (std::vector<std::pair<int,int> >::iterator itp = _v_pairs.begin(); itp != _v_pairs.end(); itp++)
    {
        std::cout << "(" << itp->first << "," << itp->second << ") ";
    }
    std::cout << std::endl;

    
    // size_t blockSize = 1;
    // while (blockSize < _v_pairs.size())
    // {
    //     for (int i = 0; i + (2 * blockSize) - 1 < _v_pairs.size(); i += blockSize * 2)
    //     {
    //         if (_v_pairs[i + blockSize - 1].second > _v_pairs[i + 2 * blockSize - 1].second)
    //         {
    //             for (int j = blockSize; j > 0; j--)
    //             {
    //                 std::pair<int,int> tmp = _v_pairs[i + blockSize - 1 - j];
    //                 _v_pairs[i + blockSize - 1 - j] = _v_pairs[i + 2 * blockSize - 1 - j];
    //                 _v_pairs[i + 2 * blockSize - 1 - j] = tmp;   
    //             }
    //         }
    //     }
    //     std::cout << "list now: ";
    //     for (std::vector<std::pair<int,int> >::iterator itp = _v_pairs.begin(); itp != _v_pairs.end(); itp++)
    //     {
    //         std::cout << "(" << itp->first << "," << itp->second << ") ";
    //     }
    //     std::cout << std::endl;
    //     blockSize *= 2;
    // }
    
    printData();

    std::cout << "list now: ";
    for (std::vector<std::pair<int,int> >::iterator itp = _v_pairs.begin(); itp != _v_pairs.end(); itp++)
    {
        std::cout << "(" << itp->first << "," << itp->second << ") ";
    }
    std::cout << std::endl;
}

