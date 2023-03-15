/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:28:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 20:31:30 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
		return 0;
	
	std::string		fileName = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];
	std::ifstream	file(fileName);
	std::ofstream	fileCopy(fileName + ".replace");
	std::string		line;

	if (!file.is_open() || !fileCopy.is_open())
	{
		std::cout << "unable to open file" << std::endl;
		return 0;
	}

	if (!s1.compare(""))
	{
		std::cout << "string to find is empty" << std::endl;
		return 0;
	}

	size_t pos;
	while (getline(file, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos,s1.length());
			line.insert(pos,s2);
			pos = line.find(s1, pos + s2.length());
		}
		fileCopy << line << std::endl;
	}
	
	file.close();
	fileCopy.close();
	
	return 0;
}
