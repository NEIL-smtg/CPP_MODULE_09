/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:36:38 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 02:46:02 by suchua           ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int>	vc;
		std::list<int>		ls;
		void	fillContainer(const char **nums);
		void	printVector();
		void	printList();
		void	sortVector();
		void	sortList();
	public:
		PmergeMe(const char **nums);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();
		void	printContainer();
		void	sort();

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
