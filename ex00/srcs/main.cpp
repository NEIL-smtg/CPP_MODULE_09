/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:57:05 by suchua            #+#    #+#             */
/*   Updated: 2023/08/26 01:10:30 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <exception>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	
	std::ifstream	ifs(av[1]);

	if (!ifs)
	{
		std::cerr << "Error : could not open file." << std::endl;
		return (1);
	}
	std::cout << "File received.." << std::endl;
	ifs.close();
	return (0);
}
