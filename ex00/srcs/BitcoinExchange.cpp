/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua < suchua@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:56:59 by suchua            #+#    #+#             */
/*   Updated: 2023/08/27 21:30:03 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *fileName)
: fileName(fileName)
{
	loadDatabase();
	// printDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this == &other)
		return (*this);
	this->db = other.db;
	this->fileName = other.fileName;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

bool	BitcoinExchange::invalidFileName()
{
	const char	*s;
	
	s = strchr(fileName, '.');
	if (!s)
		return (false);
	return (!strncmp(s, ".csv", 4));
}

//	skip the first line
void	BitcoinExchange::loadDatabase()
{
	std::ifstream	file(fileName);
	if (!file)
		throw FileOpenErrorException();
	if (!invalidFileName())
		throw InvalidFileNameException();
	
	char	*date;
	float	price;
	
	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		date = strtok(const_cast<char *>(line.c_str()), ",");
		price = std::atof(strtok(NULL, "|"));
		db.insert(std::make_pair(static_cast<std::string>(date), price));
	}
}

void	BitcoinExchange::printDatabase()
{
	std::map<std::string, float>::iterator	it;

	for (it = db.begin(); it != db.end(); it++)
	{
		std::cout << "Date : " << (*it).first;
		std::cout << " Price : " << (*it).second << std::endl;
	}
}

//	2011-01-03 => 3 = 0.9
void	BitcoinExchange::printResult(std::string date, float price,
	float value)
{
	std::cout << date << " => " << value << " * " << price;
	std::cout << " = " << price * value;
	std::cout << std::endl;
}

void	getYmd(int &yr, int &month, int &day, const char *date)
{
	yr = atoi(date);
	date = strchr(date, '-') + 1;
	month = atoi(date);
	date = strchr(date, '-') + 1;
	day = atoi(date);
}

void	BitcoinExchange::search(std::pair<std::string, float> key)
{
	std::map<std::string, float>::iterator	it;

	it = db.find(key.first);
	if (it == db.end())
		it = db.lower_bound(key.first);
	printResult((*it).first, (*it).second, key.second);
}

bool	errorMsg(std::string str)
{
	std::cerr << str;
	return (false);
}

//	YEAR-MONTH-DAY
/*
	A year is a leap year if it is divisible by 4.
	However, if a year is divisible by 100, it is not a leap year,
	unless the year is divisible by 400.
	In that case, it is a leap year.
*/
bool	BitcoinExchange::dateValidator(char *date)
{
	char	*ptr;
	int		month;
	int		day;
	int		year;

	if (!date)
		return (errorMsg("Error : Missing value.\n"));
	ptr = strtok(date, "-");
	year = std::atoi(ptr);

	ptr = strtok(NULL, "-");
	month = std::atoi(ptr);
	if (!ptr || month < 1 || month > 12)
		return (errorMsg("Error : bad input (month) =>"));

	ptr = strtok(NULL, "-");
	day = std::atoi(ptr);
	if (!ptr || day < 1 || day > 31)
		return (errorMsg("Error : bad input (day) =>"));

	if (month == 2 && year % 4 == 0)
	{
		if (year % 100 == 0 && year % 400 != 0 && day > 28)
			return (errorMsg("Error : bad input (day) =>"));
		else if (year % 4 == 0 && day > 29)
			return (errorMsg("Error : bad input (day) =>"));
	}
	
	if (month == 8 && day > 30)
		return (errorMsg("Error : bad input (day) =>"));
	
	return (true);
}

bool	BitcoinExchange::valueValidator(char *valueChar)
{
	if (!valueChar)
		return (errorMsg("Error : Missing value.\n"));
	float	value;
	value = std::atof(valueChar);
	if (value < 0.0f)
		return (errorMsg("Error : Not a positive number\n"));
	if (value > 1000.0f)
		return (errorMsg("Error : too large a number\n"));
	return (value >= 0.0f && value <= 1000.0f);	
}
