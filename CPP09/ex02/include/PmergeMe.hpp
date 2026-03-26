/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:03 by spunyapr          #+#    #+#             */
/*   Updated: 2026/03/26 13:59:36 by spunyapr         ###   ########.fr       */
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
};

bool isValidInput(int ac, char **av);

#endif
