/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:55:52 by suchua            #+#    #+#             */
/*   Updated: 2023/08/26 23:46:40 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE_HPP__
# define __BITCOIN_EXCHANGE_HPP__

# include <iostream>
# include <algorithm>
# include <vector>
# include <fstream>
# include <map>
# include <string>
# include <exception>

# define CURR_YR	2023
# define ODD_DAYS	31
# define EVEN_DAYS	30

class BitcoinExchange
{
	private:
		const char				*fileName;
		std::map<std::string, float>	db;
		void	loadDatabase();
		bool	invalidFileName();
		void	printDatabase();
		void	printResult(std::string date, float price, float value);
	public:
		BitcoinExchange(const char *fileName);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		bool	dateValidator(char *date);
		bool	valueValidator(char *valueCh);
		void	search(std::pair<std::string, float> key);

		class FileOpenErrorException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error opening .csv file");
				}
		};

		class InvalidFileNameException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Error, database name should be a .csv file.\n");
				}
		};
		
};

#endif
