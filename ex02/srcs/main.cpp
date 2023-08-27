/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 02:02:29 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 02:48:07 by suchua           ###   ########.fr       */
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
		std::cout << "Before : ";
		pm.printContainer();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
}
