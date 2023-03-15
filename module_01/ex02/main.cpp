/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:25:14 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/15 02:41:24 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPtr = &str;
	std::string &strRef = str;

	std::cout << "str: " << str << std::endl;
	std::cout << "strPtr: " << *strPtr << std::endl;
	std::cout << "strRef: " << strRef << std::endl;

	std::cout << "str address: " << &str << std::endl;
	std::cout << "strPtr address: " << strPtr << std::endl;
	std::cout << "strRef address: " << &strRef << std::endl;
	return 0;
}