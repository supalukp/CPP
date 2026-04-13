/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:07 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/13 14:51:56 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>

PmergeMe::PmergeMe(void) : _v_leftover(false), _v_left_value(0) { }

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

    while (level > 1)
    // for (int i = level; i > 1; i--)
    {
        std::cout << "\n-----------------------\n\n";
        std::cout << "level: " << level << std::endl;
        std::cout << "_v_pairs.size(): " << _v_pairs.size() << std::endl;
        std::cout << "pairPerBlock: " << getPairPerBlock(level) << std::endl;
        std::vector<int> blocks = buildBlocks(_v_pairs.size(), getPairPerBlock(level));
        std::cout << "blockSize(): " << blocks.size() << std::endl;
        std::vector<int> main;
        std::vector<int> pend;
        setMainPend(main, pend, blocks);
        std::cout << "main: ";
        for (size_t b = 0; b < main.size(); b++)
            std::cout << main[b] << " ";
        std::cout << std::endl;

        std::cout << "pend: ";
        for (size_t d = 0; d < pend.size(); d++)
            std::cout << pend[d] << " ";
        std::cout << std::endl;
        for (size_t j = 0; j < blocks.size(); j++)
        {
            std::cout << "\n------\n";
            std::cout << "blockStart: " << blocks[j] << std::endl;
            std::cout << "blockEnd: " << getBlockEnd(blocks[j], getPairPerBlock(level)) << std::endl;
            std::cout << "key: " << getBlockKey(blocks[j], getPairPerBlock(level)) << std::endl;

            if (j != 0 && j % 2 == 0)
            {
                std::cout << "b_i: " << blocks[j] << std::endl;
                std::cout << "a_i value: " << getBoundPartner(blocks[j], getPairPerBlock(level)) << std::endl;
                std::cout << "a_i position: " << getPositionBoundInMain(main, getBoundPartner(blocks[j], getPairPerBlock(level))) << std::endl;
            }
        }
        
        std::cout << "++++++++++++++++\n";
        for (size_t k = 0; k < pend.size(); k++)
        {
            std::cout << "main: ";
            for (size_t x = 0; x < main.size(); x++)
            {
                std::cout << main[x] << " ";
            }
            std::cout << "\nkey: ";
            for (size_t j = 0; j < main.size(); j++)
            {
                std::cout << getBlockKey(main[j], getPairPerBlock(level)) << " ";
            }
            std::cout << std::endl;

            std::cout << "pend: ";
            for (size_t f = 0; f < pend.size(); f++)
                std::cout << pend[f] << " ";
            std::cout << std::endl;
            std::cout << "pend " << k << " value: " << pend[k] << " : insert bound is " << getBoundPartner(pend[k], getPairPerBlock(level)) << std::endl;
            std::cout << "insert position is: " << getPairInsertPosition(main, pend[k], getPairPerBlock(level)) << std::endl;
            insertPendToMain(main, pend[k], getPairInsertPosition(main, pend[k], getPairPerBlock(level)));
            std::cout << "\n ---main: ";
            for (size_t x = 0; x < main.size(); x++)
                std::cout << main[x] << " ";
            std::cout << "\nkey: ";
            for (size_t s = 0; s < main.size(); s++)
            {
                std::cout << getBlockKey(main[s], getPairPerBlock(level)) << " ";
            }
            std::cout << std::endl;
            // std::cout << "pend: ";
            // for (size_t level = 0; level < pend.size(); level++)
            //     std::cout << pend[level] << " ";
            // std::cout << std::endl;
        }
        rebuildPair(main, getPairPerBlock(level));
        printList(_v_pairs);
        // std::vector<int> main;
        // std::vector<int> pend;

        // setMainPend(main, pend, blocks);

        // std::cout << "main: ";
        // for (size_t i = 0; i < main.size(); i++)
        //     std::cout << main[i] << " ";
        // std::cout << std::endl;

        // std::cout << "pend: ";
        // for (size_t i = 0; i < pend.size(); i++)
        //     std::cout << pend[i] << " ";
        // std::cout << std::endl;
        level--;
    }
    std::cout << "level ===== " << level << std::endl;
    // 1. build vector of new list + if has left over
    _v_sort = buildNewList();
    std::cout << "newList: ";
    for (size_t i = 0; i < _v_sort.size(); i++)
        std::cout << _v_sort[i] << " ";
    std::cout << std::endl;
    // 2. main and pend
    std::vector<int> block = buildBlocks( _v_sort.size(), 1);
    std::cout << "block: ";
    for (size_t i = 0; i < block.size(); i++)
        std::cout <<block[i] << " ";
    std::cout << std::endl;
    std::vector<int> main;
    std::vector<int> pend;
    setMainPend(main, pend, block);
    std::cout << "main: ";
    for (size_t b = 0; b < main.size(); b++)
        std::cout << main[b] << " ";
    std::cout << std::endl;

    std::cout << "pend: ";
    for (size_t d = 0; d < pend.size(); d++)
        std::cout << pend[d] << " ";
    std::cout << std::endl;
    // 3. insert
    for (size_t k = 0; k < pend.size(); k++)
    {
        insertPendToMain(main, pend[k], getIntInsertPosition(main, pend[k]));
    }
    std::cout << "main: ";
    for (size_t b = 0; b < main.size(); b++)
        std::cout << main[b] << " ";
    std::cout << std::endl;
    // 4. rebuild list
    rebuildList(main);
    std::cout << "Final: ";
    for (size_t i = 0; i < _v_sort.size(); i++)
        std::cout << _v_sort[i] << " ";
    std::cout << std::endl;
}

// for int
std::vector<int> PmergeMe::buildNewList()
{
    std::vector<int> ret;
    for (size_t i = 0; i < _v_pairs.size(); i++)
    {
        ret.push_back(_v_pairs[i].first);
        ret.push_back(_v_pairs[i].second);
    }
    if (_v_leftover == true)
        ret.push_back(_v_left_value);
    return (ret);
}

int PmergeMe::getIntKey(int bStart)
{
    return (_v_sort[bStart]);
}

int PmergeMe::intBinarySearch(std::vector<int> &main, int key, int left, int right)
{
    while (left <= right)
    {
        // std::cout << "left = " << left << " right = " << right << std::endl;
        int mid = left + ((right - left) / 2);
        int key_main_mid = getIntKey(main[mid]);
        if (key == key_main_mid)
            return (mid + 1);
        else if (key > key_main_mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

int PmergeMe::getIntInsertPosition(std::vector<int> &main, int bStart)
{
    int aStart = getIntBoundPartner(bStart);
    int bound = getPositionBoundInMain(main, aStart);
    int b_key = getIntKey(bStart);
    int main_size = static_cast<int>(main.size());
    if (bound == -1)
        bound = main_size;
    int pos = intBinarySearch(main, b_key, 0, bound - 1);
    return (pos);
}

int PmergeMe::getIntBoundPartner(int bStart)
{
    size_t aStart = bStart + 1;
    if (aStart == _v_sort.size())
        return (-1);
    return (aStart);
}


void PmergeMe::rebuildList(std::vector<int> &main)
{
    std::vector<int> newList;
    for(size_t i = 0; i < main.size(); i++)
    {
        newList.push_back(_v_sort[main[i]]);
    }
    _v_sort = newList;
}

// for std::pair
int PmergeMe::getPairPerBlock(int level)
{
    if (level <= 1)
        return (0);
    int pairPerBlock = 1;
    while (level > 2)
    {
        pairPerBlock *= 2;
        level--;
    }
    return (pairPerBlock);
}

int PmergeMe::getBlockEnd(int blockStart, int pairPerBlock)
{
    return (blockStart + pairPerBlock - 1);   
}

int PmergeMe::getBlockKey(int blockStart, int pairPerBlock)
{
    int blockEnd = getBlockEnd(blockStart, pairPerBlock);
    return (_v_pairs[blockEnd].second);
}

std::vector<int> PmergeMe::buildBlocks(int pairSize, int pairPerBlock)
{
    std::vector<int> blocks;
    // if (pairPerBlock == 0)
    //     pairPerBlock++;
    for(int i = 0; i + pairPerBlock <= pairSize; i += pairPerBlock)
    {
        blocks.push_back(i);
    }
    return (blocks);
}

void PmergeMe::setMainPend(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &blocks)
{
    for (size_t i = 0; i < blocks.size(); i++)
    {
        if (i == 0 || i % 2 == 1)
            main.push_back(blocks[i]);
        else
            pend.push_back(blocks[i]);
    }
}

// return (-1) mean no partner
int PmergeMe::getBoundPartner(int bStart, int pairPerBlock)
{
    size_t aStart = bStart + pairPerBlock;
    if (aStart + pairPerBlock > _v_pairs.size())
        return (-1);
    return (aStart);
}

int PmergeMe::getPositionBoundInMain(std::vector<int> &main, int aStart)
{
    if (aStart == -1)
        return (-1);
    for (size_t i = 0; i < main.size(); i++)
    {
        if (main[i] == aStart)
            return (i);
    }
    return (-1);
}

int PmergeMe::binarySearch(std::vector<int> &main, int key, int left, int right, int pairPerBlock)
{
    while (left <= right)
    {
        // std::cout << "left = " << left << " right = " << right << std::endl;
        int mid = left + ((right - left) / 2);
        int key_main_mid = getBlockKey(main[mid], pairPerBlock);
        if (key == key_main_mid)
            return (mid + 1);
        else if (key > key_main_mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

int PmergeMe::getPairInsertPosition(std::vector<int> &main, int bStart, int pairPerBlock)
{
    int aStart = getBoundPartner(bStart, pairPerBlock);
    int bound = getPositionBoundInMain(main, aStart);
    int b_key = getBlockKey(bStart, pairPerBlock);
    int main_size = static_cast<int>(main.size());
    if (bound == -1)
        bound = main_size;
    int pos = binarySearch(main, b_key, 0, bound - 1, pairPerBlock);
    return (pos);
}

void PmergeMe::insertPendToMain(std::vector<int> &main, int bStart, int insertPos)
{
    main.insert(main.begin() + insertPos, bStart);   
}

void PmergeMe::rebuildPair(std::vector<int> &main, int pairPerBlock)
{
    std::vector<std::pair<int,int> > newList;
    for(size_t i = 0; i < main.size(); i++)
    {
        for(int j = 0; j < pairPerBlock; j++)
        {
            newList.push_back(_v_pairs[main[i] + j]);
        }
    }
    size_t paircount = pairPerBlock * main.size();
    if (paircount < _v_pairs.size())
    {
        for (size_t i = paircount; i < _v_pairs.size(); i++)
        {
            newList.push_back(_v_pairs[i]);
        }
    }
    _v_pairs = newList;
}

std::vector<int> PmergeMe::getJacobStahlOrder(int pendSize)
{
    std::vector<int> indexOrder;
    if (pendSize <= 0)
        return (indexOrder);
        
    std::vector<int> jacobSequence;
    jacobSequence.push_back(1);
    
    int lastB = pendSize + 1;
    int prev2 = 0;
    int prev1 = 1;
    while (true)
    {
        int next = prev1 + (2 * prev2);
        prev2 = prev1;
        prev1 = next;

        if (next > 1)
            jacobSequence.push_back(next);
        if (next > lastB)
            break;
    }

    for (size_t i = 1; i < jacobSequence.size(); i++)
    {
        int prev = jacobSequence[i - 1];
        int min = std::min(jacobSequence[i], lastB);
        while (min > prev)
        {
            indexOrder.push_back(min - 2);
            min--;
        }
    }
    return (indexOrder);
}
