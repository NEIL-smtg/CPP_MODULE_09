/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:35:37 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 02:48:41 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const char **nums) {fillContainer(nums);}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other) {*this = other;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return (*this);
	this->vc = other.vc;
	this->ls = other.ls;
	return (*this);
}

bool	validInput(const char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (false);
	}
	return (true);
}

void	PmergeMe::fillContainer(const char **nums)
{
	for (int i = 1; nums[i]; i++)
	{
		if (!validInput(nums[i]))
			throw InvalidInputException();
		int	n = std::atoi(nums[i]);
		vc.push_back(n);
		ls.push_back(n);
	}
}

void	PmergeMe::printContainer()
{
	printVector();
}

void	PmergeMe::printVector()
{
	std::vector<int>::iterator	it;

	for (it = vc.begin(); it !=  vc.end(); ++it)
		std::cout << (*it) << " ";
	std::cout << "\n";
}

void	PmergeMe::printList()
{
	std::list<int>::iterator	it;

	for (it = ls.begin(); it !=  ls.end(); ++it)
		std::cout << (*it) << " ";
	std::cout << "\n";
}

void	PmergeMe::sortVector()
{
	
}

void	PmergeMe::sortList()
{
	
}

void	PmergeMe::sort()
{
	sortVector();
	sortList();
}
