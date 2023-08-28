/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:35:37 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 20:37:09 by suchua           ###   ########.fr       */
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
	this->dq = other.dq;
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
		dq.push_back(n);
	}
}

void	PmergeMe::printContainer()
{
	printList();
}

void	PmergeMe::printVector()
{
	std::vector<int>::iterator	it;

	for (it = vc.begin(); it !=  vc.end(); ++it)
		std::cout << (*it) << std::endl;
}

void	PmergeMe::printList()
{
	std::deque<int>::iterator	it;

	for (it = dq.begin(); it !=  dq.end(); ++it)
		std::cout << (*it) << std::endl;
}

void	vecInsertionSort(std::vector<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int key = arr[i];
			for (int j = i - 1; j >= left; --j)
			{
				if (arr[j] > key)
					std::swap(arr[j], arr[j + 1]);
			}			
		}
	}
}

void	vecMerge(std::vector<int>& arr, int left, int mid, int right)
{
	std::vector<int> leftArr;
	std::vector<int> rightArr;

	for (int i = left; i <= mid; i++)
		leftArr.push_back(arr[i]);
	
	for (int i = mid + 1; i <= right; i++)
		rightArr.push_back(arr[i]);	
	
	int	i = 0, j = 0, k = left;
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	while (i < n1 && j < n2)
	{
		if (leftArr[i] < rightArr[j])
			arr[k] = leftArr[i++];
		else
			arr[k] = rightArr[j++];
		++k;
	}
	while (i < n1)
		arr[k++] = leftArr[i++];
	while (j < n2)
		arr[k++] = rightArr[j++];
}

void	vecMergeInsertion(std::vector<int>& arr, int left, int right, int insertionVal)
{
	if (right - left <= insertionVal)
		vecInsertionSort(arr, left, right);
	else
	{
		int	mid = (right - left) / 2 + left;
		vecMergeInsertion(arr, left, mid, insertionVal);
		vecMergeInsertion(arr, mid + 1, right, insertionVal);
		vecMerge(arr, left, mid, right);
	}
}

void	dqInsertionSort(std::deque<int>& arr, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int key = arr[i];
			for (int j = i - 1; j >= left; --j)
			{
				if (key < arr[j])
					std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void	dqMerge(std::deque<int>& arr, int left, int mid, int right)
{
	std::deque<int>	leftQ;
	std::deque<int>	rightQ;

	for (int i = left; i <= mid; i++)
		leftQ.push_back(arr[i]);

	for (int i = mid + 1; i <= right; i++)
		rightQ.push_back(arr[i]);

	int	i = 0, j = 0, k = left;
	int	n1 = mid - left + 1;
	int	n2 = right - mid;

	while (i < n1 && j < n2)
	{
		if (leftQ[i] < rightQ[j])
			arr[k] = leftQ[i++];
		else
			arr[k] = rightQ[j++];
		++k;
	}

	while (i < n1)
		arr[k++] = leftQ[i++];
	while (i < n2)
		arr[k++] = rightQ[j++];
}

void	dqMergeInsertion(std::deque<int>& arr, int left, int right, int insertionVal)
{
	if (right - left <= insertionVal)
		dqInsertionSort(arr, left, right);
	else
	{
		int	mid = (right - left) / 2 + left;
		dqMergeInsertion(arr, left, mid, insertionVal);
		dqMergeInsertion(arr, mid + 1, right, insertionVal);
		dqMerge(arr, left, mid, right);
	}
}

int	getInsertionVal(int n)
{
	if (n <= 30) return n / 3;
    if (n <= 100) return n / 10;
    if (n <= 500) return n / 25;
    if (n <= 1000) return n / 50;
    return n / 100;
}

void	PmergeMe::sort()
{
	int	n = static_cast<int>(vc.size());
	int	insertionVal = getInsertionVal(n);

	before = clock();
	vecMergeInsertion(vc, 0, n - 1, insertionVal);
	after = clock();
	vecRunTime = static_cast<double>(after - before) / CLOCKS_PER_SEC;

	before = clock();
	dqMergeInsertion(dq, 0, n - 1, insertionVal);
	after = clock();
	listRunTime = static_cast<double>(after - before) / CLOCKS_PER_SEC;
}

void	PmergeMe::printRunTime()
{
	std::cout << "Time to process a range of " << vc.size();
	std::cout << " elements with std::vector<int> : ";
	std::cout << std::fixed << std::setprecision(5) << vecRunTime << " s" << std::endl;

	std::cout << "Time to process a range of " << dq.size();
	std::cout << " elements with std::deque<int> : ";
	std::cout << std::fixed << std::setprecision(5) << listRunTime << " s" << std::endl;
}

void	PmergeMe::checkSorted()
{
	std::vector<int>::iterator	v;
	std::deque<int>::iterator	d;

	for (v = vc.begin() + 1; v != vc.end(); v++)
	{
		if ((*v) < (*(v - 1)))
		{
			std::cout << "std::vector Not sorted" << std::endl;
			return ;
		}
	}
	
	for (d = dq.begin() + 1; d != dq.end(); d++)
	{
		if ((*d) < (*(d - 1)))
		{
			std::cout << "std::deque Not sorted" << std::endl;
			return ;
		}
	}
	std::cout << "Both sorted !\n";
}
