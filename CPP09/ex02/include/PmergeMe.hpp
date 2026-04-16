/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:03 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/16 14:20:54 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <deque>
#include <vector>
#include <time.h>

class PmergeMe
{
    private:
        std::vector<int>                    _v_input;
        std::vector<int>                    _v_sort;
        std::vector<std::pair<int, int> >   _v_pairs;
        size_t                              _v_comparisons;

        std::deque<int>                     _d_input;
        std::deque<int>                     _d_sort;
        std::deque<std::pair<int, int> >    _d_pairs;
        size_t                              _d_comparisons;
        
        bool                                _leftover;
        int                                 _left_value;
        
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe(void);

        // Parsing both vector and deque
        int                 storeValidInput(int ac, char **av);

        // Ford-Johnson
        void                runFordJohnsonVector();
        void                runFordJohnsonDeque();

        // print result
        void                printResult(clock_t dif_vector, clock_t dif_deque);

        // Ford-Johnson Vector
        void                v_storeOddLeftOver();
        void                v_makeInitPairs();
        void                v_sortWinnerBlock(int &level, size_t &blockSize);
        void                v_insertPairLevels(int &level);
        void                v_makePairtoInt();
        void                v_sortFinalIntLevel();

        // Helper for Vector
        int                 v_getPairPerBlock(int level);
        int                 v_getBlockEnd(int blockStart, int pairPerBlock);
        int                 v_getBlockKey(int blockStart, int pairPerBlock);
        std::vector<int>    v_buildBlocks(int pairSize, int pairPerBlock);
        int                 v_getBoundPartner(int bStart, int pairPerBlock);
        int                 v_getPositionBoundInMain(std::vector<int> &main, int aStart);
        int                 v_getPairInsertPosition(std::vector<int> &main, int bStart, int pairPerBlock);
        int                 v_binarySearch(std::vector<int> &main, int key, int left, int right, int pairPerBlock);
        void                v_insertPendToMain(std::vector<int> &main, int bStart, int insertPos);
        void                v_rebuildPair(std::vector<int> &main, int pairPerBlock);
        int                 v_getIntBoundPartner(int bStart);
        int                 v_getIntInsertPosition(std::vector<int> &main, int bStart);
        int                 v_getIntKey(int bStart);
        int                 v_intBinarySearch(std::vector<int> &main, int key, int left, int right);
        void                v_rebuildList(std::vector<int> &main);
        std::vector<int>    v_getJacobStahlOrder(int pendSize);

        // Ford-Johnson Deque
        void                d_storeOddLeftOver();
        void                d_makeInitPairs();
        void                d_sortWinnerBlock(int &level, size_t &blockSize);
        void                d_insertPairLevels(int &level);
        void                d_makePairtoInt();
        void                d_sortFinalIntLevel();

        // Helper for Deque
        int                 d_getPairPerBlock(int level);
        int                 d_getBlockEnd(int blockStart, int pairPerBlock);
        int                 d_getBlockKey(int blockStart, int pairPerBlock);
        std::deque<int>     d_buildBlocks(int pairSize, int pairPerBlock);
        int                 d_getBoundPartner(int bStart, int pairPerBlock);
        int                 d_getPositionBoundInMain(std::deque<int> &main, int aStart);
        int                 d_getPairInsertPosition(std::deque<int> &main, int bStart, int pairPerBlock);
        int                 d_binarySearch(std::deque<int> &main, int key, int left, int right, int pairPerBlock);
        void                d_insertPendToMain(std::deque<int> &main, int bStart, int insertPos);
        void                d_rebuildPair(std::deque<int> &main, int pairPerBlock);
        int                 d_getIntBoundPartner(int bStart);
        int                 d_getIntInsertPosition(std::deque<int> &main, int bStart);
        int                 d_getIntKey(int bStart);
        int                 d_intBinarySearch(std::deque<int> &main, int key, int left, int right);
        void                d_rebuildList(std::deque<int> &main);
        std::deque<int>     d_getJacobStahlOrder(int pendSize);
};

#endif
