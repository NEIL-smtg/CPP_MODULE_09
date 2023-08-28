/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:36:38 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 20:29:27 by suchua           ###   ########.fr       */
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
		void	printList();
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

#endif
