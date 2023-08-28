/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 02:02:29 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 20:30:39 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, const char **av)
{
	if (ac == 1)
	{
		std::cerr << "Incorrect number of arguments" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	pm(av);
		std::cout << "Before : \n";
		pm.printContainer();
		pm.sort();
		std::cout << "After : \n";
		pm.printContainer();
		pm.printRunTime();
		pm.checkSorted();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
