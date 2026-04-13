/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:03 by spunyapr          #+#    #+#             */
/*   Updated: 2026/04/13 14:51:30 by spunyapr         ###   ########.fr       */
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
        // std::deque<int> _d_main;
        // std::deque<int> _d_pend;
        std::vector<int> _v_input;
        std::vector<int> _v_sort;
        std::vector<std::pair<int, int> >  _v_pairs;
        // std::vector<int> _v_main;
        // std::vector<int> _v_pending;
        bool _v_leftover;
        int _v_left_value;
        // int _v_level;
        
        
    public:
        PmergeMe(void);
        // PmergeMe(const PmergeMe& other);
        // PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe(void);

        
        void addValueToMain(int value);
        void printMain();

        void orderPair();
        void printData(void);
        int getPairPerBlock(int level);
        int getBlockEnd(int blockStart, int pairPerBlock);
        int getBlockKey(int blockStart, int pairPerBlock);
        std::vector<int> buildBlocks(int pairSize, int pairPerBlock);
        void setMainPend(std::vector<int> &main, std::vector<int> &pend, std::vector<int> &blocks);
        int getBoundPartner(int bStart, int pairPerBlock);
        int getPositionBoundInMain(std::vector<int> &main, int aStart);
        int getPairInsertPosition(std::vector<int> &main, int bStart, int pairPerBlock);
        int binarySearch(std::vector<int> &main, int key, int left, int right, int pairPerBlock);
        void insertPendToMain(std::vector<int> &main, int bStart, int insertPos);
        void rebuildPair(std::vector<int> &main, int pairPerBlock);
        std::vector<int> buildNewList();
        int getIntBoundPartner(int bStart);
        int getIntInsertPosition(std::vector<int> &main, int bStart);
        int getIntKey(int bStart);
        int intBinarySearch(std::vector<int> &main, int key, int left, int right);
        void rebuildList(std::vector<int> &main);
        std::vector<int> getJacobStahlOrder(int pendSize);
};

bool isValidInput(int ac, char **av);

#endif
