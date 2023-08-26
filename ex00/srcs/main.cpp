/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:57:05 by suchua            #+#    #+#             */
/*   Updated: 2023/08/27 00:11:18 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//	skip the first line
void	processLine(std::ifstream& infile, BitcoinExchange &b)
{
	std::string	line;
	char		*dateChar;
	char		*dateBackupChar;
	char		*valueChar;
	float		value;
	std::string	date;
	bool		skip;

	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		skip = false;
		dateChar = strtok(const_cast<char *>(line.c_str()), " |");
		if (!dateChar)
			continue ;
		valueChar = strtok(NULL, " |");
		dateBackupChar = new char[strlen(dateChar + 1)];
		strcpy(dateBackupChar, dateChar);
		if (!b.dateValidator(dateBackupChar))
		{
			std::cerr << " " << line << std::endl;
			skip = true;
		}
		if (!b.valueValidator(valueChar))
			skip = true;
		delete dateBackupChar;
		if (skip)
			continue ;
		date = static_cast<std::string>(dateChar);
		value = std::atof(valueChar);
		b.search(std::make_pair(date, value));
	}
}

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
	try
	{
		BitcoinExchange	b("btc_history.csv");
		processLine(ifs, b);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
