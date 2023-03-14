/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:37:46 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/11 19:37:53 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void uppercase(char **args)
{
	for (size_t i = 1; args[i]; i++)
	{
		for (size_t j = 0; args[i][j]; j++)
			std::cout << (char)std::toupper(args[i][j]);
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		uppercase(argv);
	return 0;
}
