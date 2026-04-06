/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:07 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/06 14:24:39 by spunyapr         ###   ########.fr       */
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

void printList(std::vector<std::pair<int,int> > _v_pairs)
{
    std::cout << "list now: ";
    for (std::vector<std::pair<int,int> >::iterator itp = _v_pairs.begin(); itp != _v_pairs.end(); itp++)
    {
        std::cout << "(" << itp->first << "," << itp->second << ") ";
    }
    std::cout << std::endl;
}

void PmergeMe::orderPair(void)
{    
    std::cout << "input size: " << _v_input.size() << std::endl;
    // 1. check left over before pair + store it
    if (_v_input.size() % 2 == 1)
    {
        _v_leftover = true;
        _v_left_value = _v_input.back();
    }
    // 2. compare position i and (i+1) if (i+1) bigger than i swap position before push back a pair to _v_pairs (Here is Recursion level 1)
    for (std::vector<int>::iterator it = _v_input.begin(); it != _v_input.end() && it + 1 != _v_input.end(); it += 2)
    {
        if (*it > *(it+1))
            _v_pairs.push_back(std::make_pair(*(it + 1), *it));
        else
            _v_pairs.push_back(std::make_pair(*it, *(it + 1)));
    }

    printData();
    printList(_v_pairs);
    
    int level = 1;
    size_t blockSize = 1;
    while (blockSize < _v_pairs.size())
    {
        std::cout << "blocksize: " << blockSize << std::endl;
        level++;
        for (size_t i = 0; i + (2 * blockSize) <= _v_pairs.size(); i += (blockSize * 2))
        {
            size_t leftEnd = i + blockSize - 1;
            size_t rightEnd = i + (2 * blockSize) - 1;

            if (_v_pairs[leftEnd].second > _v_pairs[rightEnd].second)
            {
                for (size_t j = 0; j < blockSize; j++)
                {
                    std::pair<int, int> tmp = _v_pairs[i + j];
                    _v_pairs[i + j] = _v_pairs[i + blockSize + j];
                    _v_pairs[i + blockSize + j] = tmp;
                }
            }
        }
        std::cout << "level: " << level << std::endl;
        printList(_v_pairs);
        blockSize *= 2;
        if (blockSize * 2 > _v_pairs.size())
            break;
    }
    printData();
}

