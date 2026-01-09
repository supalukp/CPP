/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:34:03 by spunyapr          #+#    #+#             */
/*   Updated: 2026/01/09 18:07:28 by spunyapr         ###   ########.fr       */
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
        
    public:
        PmergeMe(void);
        // PmergeMe(const PmergeMe& other);
        // PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe(void);

        
        void addValueToMain(int value);
        void printMain();

        std::vector<int> getWinnerList(std::vector<int> list);
};

bool isValidInput(int ac, char **av);

#endif
