/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:36:38 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 20:43:03 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGE_ME_HPP__
# define __PMERGE_ME_HPP__

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <exception>
# include <algorithm>
# include <ctime>
# include <unistd.h>
# include <iomanip>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int>	vc;
		std::deque<int>		dq;
		void	fillContainer(const char **nums);
		void	printVector();
		void	printQueue();
		clock_t	before;
		clock_t	after;
		double	vecRunTime;
		double	listRunTime;
	public:
		PmergeMe(const char **nums);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	printContainer();
		void	sort();
		void	printRunTime();
		void	checkSorted();

		class InvalidInputException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return "Error : Invalid input, input should only be positive numbers.\n";					
				}
		};
};

/*
Dynamic Resizing:

std::deque:
	Deques can dynamically resize and grow/shrink in size like vectors.
	However, deques usually manage their memory differently.
	They typically use a sequence of fixed-size memory blocks,
	allowing efficient insertion and deletion at both ends
	without the need for frequent reallocations.

std::vector:
	Vectors also dynamically resize,
	but they use a single contiguous block of memory.
	When a vector needs to grow beyond its current capacity,
	it reallocates memory for the entire vector,
	which can be an expensive operation.

Insertion and Deletion Performance:

std::deque:
	Deques excel at insertion and deletion at both the beginning and end.
	These operations are usually more efficient than in vectors
	because deques don't need to move a large number of elements during resizing.

std::vector:
	While vectors are efficient at random access,
	they might incur more overhead when inserting or deleting elements
	at the beginning or in the middle due to potential memory reallocation.

Random Access Performance:

std::deque:
	Deques offer random access to elements (similar to vectors),
	but vectors might have slightly better performance
	in this regard due to their contiguous memory layout.

std::vector:
	Vectors have efficient random access to elements
	due to their contiguous memory layout.

Memory Layout:

std::deque:
	Deques are composed of a series of fixed-size memory blocks,
	and elements are stored in those blocks.
	This structure allows deques to avoid
	large reallocations when growing or shrinking.

std::vector:
	Vectors use a single contiguous block of memory to store elements.

Memory Overhead:

std::deque: Deques might have slightly higher memory overhead compared to vectors due to their block-based memory management.
std::vector: Vectors have minimal memory overhead, as they store elements in a single block of memory.
Usage:

std::deque:
	Use deques when you need efficient insertion
	and deletion at both ends of the container.
	Deques are especially useful when
	you want to avoid frequent reallocations that vectors might incur.

std::vector:
	Use vectors when you need efficient
	random access and dynamic resizing,
	particularly if you primarily
	work with elements in the middle of the container.
*/

#endif
