/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la- <aude-la-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:08:36 by aude-la-          #+#    #+#             */
/*   Updated: 2024/11/07 12:14:10 by aude-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string	replaceALL(std::string line, const std::string& s1, const std::string& s2)
{
	std::size_t	pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos += s2.length();
	}
	return (line);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (std::cerr << "Agrguments needed are : <filename> s1 s2" << std::endl, 1);
	std::string file = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (s1.empty())
		return (std::cerr << "s1 cannot be empty" << std::endl, 1);
	std::ifstream inputFile(file.c_str());
	if (!inputFile.is_open())
		return (std::cerr << "Error: Cannot open the input file " << file << std::endl, 1);
	std::ofstream outputFile((file + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: Cannot open the output file " << file << ".replace" << std::endl;
		return (inputFile.close(), 1);
	}
	std::string	line;
	while (std::getline(inputFile, line))
		outputFile << replaceALL(line, s1, s2) << std::endl;
	inputFile.close();
	outputFile.close();

	return (0);
}
