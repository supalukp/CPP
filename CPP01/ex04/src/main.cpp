/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:57:24 by spunyapr          #+#    #+#             */
/*   Updated: 2025/09/09 11:48:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main (int ac, char *av[])
{   
    std::string buffer;
    std::string contents;
    std::ifstream infile;
    std::ofstream outfile;
    std::string outfileName;
    
    if (ac != 4)
    {
        std::cout << "Input: ./sed <filename> <string1> <string2> \n";
        return (1);
    }
    if (std::string(av[1]).empty() || std::string(av[2]).empty() || std::string(av[3]).empty())
    {
        std::cout << "No empty arguments allowed\n";
        return (1);
    }

    infile.open(av[1]);
    if (!infile.is_open())
    {
        std::cerr << "Error opening infile\n";
        return (1);
    }
    while (std::getline(infile, buffer))
    {
        if (infile.eof())
            contents += buffer;
        else
            contents += buffer + '\n';
    }
    infile.close();
    
    ft_sed(contents, av[2], av[3]);
    
    outfileName = std::string(av[1]) + ".replace";
    outfile.open(outfileName.c_str());
    if (!outfile.is_open()) 
    {
        std::cerr << "Error opening outfile\n";
        return 1;
    }
    outfile << contents;
    if (outfile.fail()) 
    {
        std::cerr << "Error writing to output file\n";
        return 1;
    }
    outfile.close();
    
    return (0);
}
