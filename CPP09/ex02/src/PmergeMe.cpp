/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:07 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/15 20:25:36 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>
#include <iomanip>

bool isValidInput(int ac, char **av);

PmergeMe::PmergeMe(void) :  _v_comparisons(0), _d_comparisons(0), _leftover(false), _left_value(0) { }

PmergeMe::~PmergeMe(void) { }

int PmergeMe::storeValidInput(int ac, char **av)
{
    if (!isValidInput(ac, av))
        return (1);
    for (int i = 1; i < ac; i++)
    {
        int value = std::atoi(av[i]);
        _v_input.push_back(value);
        _d_input.push_back(value);
    }
    return (0);
}

void PmergeMe::runFordJohnsonVector()
{
    _v_comparisons = 0;
    // 1. detect odd left over
    v_storeOddLeftOver();
    // 2. create pair
    v_makeInitPairs();
    // 3. sort winner block
    int level = 1;
    size_t blockSize = 1;
    v_sortWinnerBlock(level, blockSize);
    // 4. recursively rebuild pair level
    v_insertPairLevels(level);
    // 5. flatten to ints
    v_makePairtoInt();
    // 6. final insertion
    v_sortFinalIntLevel();
    // 7. print result
}

void PmergeMe::printResult(clock_t dif_vector, clock_t dif_deque)
{
    std::cout << "Before V: ";
    for (std::vector<int>::const_iterator it = _v_input.begin(); it != _v_input.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After V: ";
    for (std::vector<int>::const_iterator it = _v_sort.begin(); it != _v_sort.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Before D: ";
    for (std::deque<int>::const_iterator it = _d_input.begin(); it != _d_input.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "After D: ";
    for (std::deque<int>::const_iterator it = _d_sort.begin(); it != _d_sort.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::fixed << std::setprecision(5);
    double time_us_vector = (static_cast<double>(dif_vector) / CLOCKS_PER_SEC) * 1000000.0;
    std::cout << "Time to process a range of " << _v_input.size() << " elements with std::vector : " << time_us_vector << " us" << std::endl;
    double time_us_deque = (static_cast<double>(dif_deque) / CLOCKS_PER_SEC) * 1000000.0;
    std::cout << "Time to process a range of " << _d_input.size() << " elements with std::deque : " << time_us_deque << " us" << std::endl;

}

void PmergeMe::v_storeOddLeftOver()
{
    if (_v_input.size() % 2 == 1)
    {
        _leftover = true;
        _left_value = _v_input.back();
    }
}

void PmergeMe::v_makeInitPairs()
{
    for (std::vector<int>::iterator it = _v_input.begin(); it != _v_input.end() && it + 1 != _v_input.end(); it += 2)
    {
        _v_comparisons++;
        if (*it > *(it+1))
            _v_pairs.push_back(std::make_pair(*(it + 1), *it));
        else
            _v_pairs.push_back(std::make_pair(*it, *(it + 1)));
    }
}

void PmergeMe::v_sortWinnerBlock(int &level, size_t &blockSize)
{
    while (blockSize < _v_pairs.size())
    {
        level++;
        for (size_t i = 0; i + (2 * blockSize) <= _v_pairs.size(); i += (blockSize * 2))
        {
            size_t leftEnd = i + blockSize - 1;
            size_t rightEnd = i + (2 * blockSize) - 1;
            _v_comparisons++;
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
        blockSize *= 2;
        if (blockSize * 2 > _v_pairs.size())
            break;
    }
}

void PmergeMe::v_insertPairLevels(int &level)
{
    while (level > 1)
    {
        std::vector<int> blocks = v_buildBlocks(_v_pairs.size(), v_getPairPerBlock(level));
        std::vector<int> main;
        std::vector<int> pend;
        for (size_t i = 0; i < blocks.size(); i++)
        {
            if (i == 0 || i % 2 == 1)
                main.push_back(blocks[i]);
            else
                pend.push_back(blocks[i]);
        }
        
        std::vector<int> jacobsthalOrder = v_getJacobStahlOrder(pend.size());
        for (size_t k = 0; k < jacobsthalOrder.size(); k++)
        {
            v_insertPendToMain(main, pend[jacobsthalOrder[k]], v_getPairInsertPosition(main, pend[jacobsthalOrder[k]], v_getPairPerBlock(level)));
        }
        v_rebuildPair(main, v_getPairPerBlock(level));
        level--;
    }
}

void PmergeMe::v_makePairtoInt()
{
    for (size_t i = 0; i < _v_pairs.size(); i++)
    {
        _v_sort.push_back(_v_pairs[i].first);
        _v_sort.push_back(_v_pairs[i].second);
    }
    if (_leftover == true)
        _v_sort.push_back(_left_value);
}

void PmergeMe::v_sortFinalIntLevel()
{
    std::vector<int> blocks = v_buildBlocks( _v_sort.size(), 1);
   
    std::vector<int> main;
    std::vector<int> pend;
    for (size_t i = 0; i < blocks.size(); i++)
    {
        if (i == 0 || i % 2 == 1)
            main.push_back(blocks[i]);
        else
            pend.push_back(blocks[i]);
    }
   
    std::vector<int> jacobsthalOrder = v_getJacobStahlOrder(pend.size());
    for (size_t k = 0; k < jacobsthalOrder.size(); k++)
    {
        v_insertPendToMain(main, pend[jacobsthalOrder[k]], v_getIntInsertPosition(main, pend[jacobsthalOrder[k]]));
    }
    v_rebuildList(main);
}

int PmergeMe::v_getIntKey(int bStart)
{
    return (_v_sort[bStart]);
}

int PmergeMe::v_intBinarySearch(std::vector<int> &main, int key, int left, int right)
{
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        int key_main_mid = _v_sort[main[mid]];

        _v_comparisons++;
        if (key > key_main_mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

int PmergeMe::v_getIntInsertPosition(std::vector<int> &main, int bStart)
{
    int aStart = v_getIntBoundPartner(bStart);
    int bound = v_getPositionBoundInMain(main, aStart);
    int b_key = _v_sort[bStart];
    int main_size = static_cast<int>(main.size());
    if (bound == -1)
        bound = main_size;
    int pos = v_intBinarySearch(main, b_key, 0, bound - 1);
    return (pos);
}

int PmergeMe::v_getIntBoundPartner(int bStart)
{
    size_t aStart = bStart + 1;
    if (aStart == _v_sort.size())
        return (-1);
    return (aStart);
}

void PmergeMe::v_rebuildList(std::vector<int> &main)
{
    std::vector<int> newList;
    for(size_t i = 0; i < main.size(); i++)
    {
        newList.push_back(_v_sort[main[i]]);
    }
    _v_sort = newList;
}

int PmergeMe::v_getPairPerBlock(int level)
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

int PmergeMe::v_getBlockEnd(int blockStart, int pairPerBlock)
{
    return (blockStart + pairPerBlock - 1);   
}

int PmergeMe::v_getBlockKey(int blockStart, int pairPerBlock)
{
    int blockEnd = v_getBlockEnd(blockStart, pairPerBlock);
    return (_v_pairs[blockEnd].second);
}

std::vector<int> PmergeMe::v_buildBlocks(int pairSize, int pairPerBlock)
{
    std::vector<int> blocks;
    for(int i = 0; i + pairPerBlock <= pairSize; i += pairPerBlock)
    {
        blocks.push_back(i);
    }
    return (blocks);
}

// return (-1) mean no partner
int PmergeMe::v_getBoundPartner(int bStart, int pairPerBlock)
{
    size_t aStart = bStart + pairPerBlock;
    if (aStart + pairPerBlock > _v_pairs.size())
        return (-1);
    return (aStart);
}

int PmergeMe::v_getPositionBoundInMain(std::vector<int> &main, int aStart)
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

int PmergeMe::v_binarySearch(std::vector<int> &main, int key, int left, int right, int pairPerBlock)
{
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        int key_main_mid = v_getBlockKey(main[mid], pairPerBlock);

        _v_comparisons++;
        if (key > key_main_mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

int PmergeMe::v_getPairInsertPosition(std::vector<int> &main, int bStart, int pairPerBlock)
{
    int aStart = v_getBoundPartner(bStart, pairPerBlock);
    int bound = v_getPositionBoundInMain(main, aStart);
    int b_key = v_getBlockKey(bStart, pairPerBlock);
    int main_size = static_cast<int>(main.size());
    if (bound == -1)
        bound = main_size;
    int pos = v_binarySearch(main, b_key, 0, bound - 1, pairPerBlock);
    return (pos);
}

void PmergeMe::v_insertPendToMain(std::vector<int> &main, int bStart, int insertPos)
{
    main.insert(main.begin() + insertPos, bStart);   
}

void PmergeMe::v_rebuildPair(std::vector<int> &main, int pairPerBlock)
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

std::vector<int> PmergeMe::v_getJacobStahlOrder(int pendSize)
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
        int current = std::min(jacobSequence[i], lastB);
        while (current > prev)
        {
            indexOrder.push_back(current - 2);
            current--;
        }
    }
    return (indexOrder);
}

void PmergeMe::runFordJohnsonDeque()
{
    _d_comparisons = 0;
    // 1. detect odd left over
    d_storeOddLeftOver();
    // 2. create pair
    d_makeInitPairs();
    // 3. sort winner block
    int level = 1;
    size_t blockSize = 1;
    d_sortWinnerBlock(level, blockSize);
    // 4. recursively rebuild pair level
    d_insertPairLevels(level);
    // 5. flatten to ints
    d_makePairtoInt();
    // 6. final insertion
    d_sortFinalIntLevel();
    // 7. print result
}


void PmergeMe::d_storeOddLeftOver()
{
    if (_d_input.size() % 2 == 1)
    {
        _leftover = true;
        _left_value = _d_input.back();
    }
}

void PmergeMe::d_makeInitPairs()
{
    for (std::deque<int>::iterator it = _d_input.begin(); it != _d_input.end() && it + 1 != _d_input.end(); it += 2)
    {
        _d_comparisons++;
        if (*it > *(it+1))
            _d_pairs.push_back(std::make_pair(*(it + 1), *it));
        else
            _d_pairs.push_back(std::make_pair(*it, *(it + 1)));
    }
}

void PmergeMe::d_sortWinnerBlock(int &level, size_t &blockSize)
{
    while (blockSize < _d_pairs.size())
    {
        level++;
        for (size_t i = 0; i + (2 * blockSize) <= _d_pairs.size(); i += (blockSize * 2))
        {
            size_t leftEnd = i + blockSize - 1;
            size_t rightEnd = i + (2 * blockSize) - 1;
            _d_comparisons++;
            if (_d_pairs[leftEnd].second > _d_pairs[rightEnd].second)
            {
                for (size_t j = 0; j < blockSize; j++)
                {
                    std::pair<int, int> tmp = _d_pairs[i + j];
                    _d_pairs[i + j] = _d_pairs[i + blockSize + j];
                    _d_pairs[i + blockSize + j] = tmp;
                }
            }
        }
        blockSize *= 2;
        if (blockSize * 2 > _d_pairs.size())
            break;
    }
}

void PmergeMe::d_insertPairLevels(int &level)
{
    while (level > 1)
    {
        std::deque<int> blocks = d_buildBlocks(_d_pairs.size(), d_getPairPerBlock(level));
        std::deque<int> main;
        std::deque<int> pend;
        for (size_t i = 0; i < blocks.size(); i++)
        {
            if (i == 0 || i % 2 == 1)
                main.push_back(blocks[i]);
            else
                pend.push_back(blocks[i]);
        }
        
        std::deque<int> jacobsthalOrder = d_getJacobStahlOrder(pend.size());
        for (size_t k = 0; k < jacobsthalOrder.size(); k++)
        {
            d_insertPendToMain(main, pend[jacobsthalOrder[k]], d_getPairInsertPosition(main, pend[jacobsthalOrder[k]], d_getPairPerBlock(level)));
        }
        d_rebuildPair(main, d_getPairPerBlock(level));
        level--;
    }
}

void PmergeMe::d_makePairtoInt()
{
    for (size_t i = 0; i < _d_pairs.size(); i++)
    {
        _d_sort.push_back(_d_pairs[i].first);
        _d_sort.push_back(_d_pairs[i].second);
    }
    if (_leftover == true)
        _d_sort.push_back(_left_value);
}

void PmergeMe::d_sortFinalIntLevel()
{
    std::deque<int> blocks = d_buildBlocks( _d_sort.size(), 1);
   
    std::deque<int> main;
    std::deque<int> pend;
    for (size_t i = 0; i < blocks.size(); i++)
    {
        if (i == 0 || i % 2 == 1)
            main.push_back(blocks[i]);
        else
            pend.push_back(blocks[i]);
    }
   
    std::deque<int> jacobsthalOrder = d_getJacobStahlOrder(pend.size());
    for (size_t k = 0; k < jacobsthalOrder.size(); k++)
    {
        d_insertPendToMain(main, pend[jacobsthalOrder[k]], d_getIntInsertPosition(main, pend[jacobsthalOrder[k]]));
    }
    d_rebuildList(main);
}

int PmergeMe::d_getIntKey(int bStart)
{
    return (_d_sort[bStart]);
}

int PmergeMe::d_intBinarySearch(std::deque<int> &main, int key, int left, int right)
{
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        int key_main_mid = _d_sort[main[mid]];

        _d_comparisons++;
        if (key > key_main_mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

int PmergeMe::d_getIntInsertPosition(std::deque<int> &main, int bStart)
{
    int aStart = d_getIntBoundPartner(bStart);
    int bound = d_getPositionBoundInMain(main, aStart);
    int b_key = _d_sort[bStart];
    int main_size = static_cast<int>(main.size());
    if (bound == -1)
        bound = main_size;
    int pos = d_intBinarySearch(main, b_key, 0, bound - 1);
    return (pos);
}

int PmergeMe::d_getIntBoundPartner(int bStart)
{
    size_t aStart = bStart + 1;
    if (aStart == _d_sort.size())
        return (-1);
    return (aStart);
}

void PmergeMe::d_rebuildList(std::deque<int> &main)
{
    std::deque<int> newList;
    for(size_t i = 0; i < main.size(); i++)
    {
        newList.push_back(_d_sort[main[i]]);
    }
    _d_sort = newList;
}

int PmergeMe::d_getPairPerBlock(int level)
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

int PmergeMe::d_getBlockEnd(int blockStart, int pairPerBlock)
{
    return (blockStart + pairPerBlock - 1);   
}

int PmergeMe::d_getBlockKey(int blockStart, int pairPerBlock)
{
    int blockEnd = d_getBlockEnd(blockStart, pairPerBlock);
    return (_d_pairs[blockEnd].second);
}

std::deque<int> PmergeMe::d_buildBlocks(int pairSize, int pairPerBlock)
{
    std::deque<int> blocks;
    for(int i = 0; i + pairPerBlock <= pairSize; i += pairPerBlock)
    {
        blocks.push_back(i);
    }
    return (blocks);
}

int PmergeMe::d_getBoundPartner(int bStart, int pairPerBlock)
{
    size_t aStart = bStart + pairPerBlock;
    if (aStart + pairPerBlock > _d_pairs.size())
        return (-1);
    return (aStart);
}

int PmergeMe::d_getPositionBoundInMain(std::deque<int> &main, int aStart)
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

int PmergeMe::d_binarySearch(std::deque<int> &main, int key, int left, int right, int pairPerBlock)
{
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        int key_main_mid = d_getBlockKey(main[mid], pairPerBlock);

        _d_comparisons++;
        if (key > key_main_mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return (left);
}

int PmergeMe::d_getPairInsertPosition(std::deque<int> &main, int bStart, int pairPerBlock)
{
    int aStart = d_getBoundPartner(bStart, pairPerBlock);
    int bound = d_getPositionBoundInMain(main, aStart);
    int b_key = d_getBlockKey(bStart, pairPerBlock);
    int main_size = static_cast<int>(main.size());
    if (bound == -1)
        bound = main_size;
    int pos = d_binarySearch(main, b_key, 0, bound - 1, pairPerBlock);
    return (pos);
}

void PmergeMe::d_insertPendToMain(std::deque<int> &main, int bStart, int insertPos)
{
    main.insert(main.begin() + insertPos, bStart);   
}

void PmergeMe::d_rebuildPair(std::deque<int> &main, int pairPerBlock)
{
    std::deque<std::pair<int,int> > newList;
    for(size_t i = 0; i < main.size(); i++)
    {
        for(int j = 0; j < pairPerBlock; j++)
        {
            newList.push_back(_d_pairs[main[i] + j]);
        }
    }
    size_t paircount = pairPerBlock * main.size();
    if (paircount < _d_pairs.size())
    {
        for (size_t i = paircount; i < _d_pairs.size(); i++)
        {
            newList.push_back(_d_pairs[i]);
        }
    }
    _d_pairs = newList;
}

std::deque<int> PmergeMe::d_getJacobStahlOrder(int pendSize)
{
    std::deque<int> indexOrder;
    if (pendSize <= 0)
        return (indexOrder);
        
    std::deque<int> jacobSequence;
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
        int current = std::min(jacobSequence[i], lastB);
        while (current > prev)
        {
            indexOrder.push_back(current - 2);
            current--;
        }
    }
    return (indexOrder);
}
