/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:03 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/15 14:41:47 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <cctype>
#include <cstring>
#include <climits>
#include <cerrno>
#include <cstdlib>

class PmergeMe
{
    private:
        std::vector<int> _v_input;
        std::vector<int> _v_sort;
        std::vector<std::pair<int, int> >  _v_pairs;
        size_t _v_comparisons;

        std::deque<int> _d_input;
        std::deque<int> _d_sort;
        std::deque<std::pair<int, int> >  _d_pairs;
        size_t _d_comparisons;
        
        bool _leftover;
        int  _left_value;
        
    public:
        PmergeMe(void);
        // PmergeMe(const PmergeMe& other);
        // PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe(void);

        // parsing both vector and deque
        int storeValidInput(int ac, char **av);

        // Ford-Johnson
        void runFordJohnsonVector();

        // print result
        void printResult();

        // Ford-Johnson Vector
        void v_storeOddLeftOver();
        void v_makeInitPairs();
        void v_sortWinnerBlock(int &level, size_t &blockSize);
        void v_insertPairLevels(int &level);
        void v_makePairtoInt();
        void v_sortFinalIntLevel();

        // helper for vector
        int v_getPairPerBlock(int level);
        int v_getBlockEnd(int blockStart, int pairPerBlock);
        int v_getBlockKey(int blockStart, int pairPerBlock);
        std::vector<int> v_buildBlocks(int pairSize, int pairPerBlock);
        int v_getBoundPartner(int bStart, int pairPerBlock);
        int v_getPositionBoundInMain(std::vector<int> &main, int aStart);
        int v_getPairInsertPosition(std::vector<int> &main, int bStart, int pairPerBlock);
        int v_binarySearch(std::vector<int> &main, int key, int left, int right, int pairPerBlock);
        void v_insertPendToMain(std::vector<int> &main, int bStart, int insertPos);
        void v_rebuildPair(std::vector<int> &main, int pairPerBlock);
        int v_getIntBoundPartner(int bStart);
        int v_getIntInsertPosition(std::vector<int> &main, int bStart);
        int v_getIntKey(int bStart);
        int v_intBinarySearch(std::vector<int> &main, int key, int left, int right);
        void v_rebuildList(std::vector<int> &main);
        std::vector<int> v_getJacobStahlOrder(int pendSize);
};

bool isValidInput(int ac, char **av);

#endif
