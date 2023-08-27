/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:24:40 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 01:34:19 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
	Infix Expression:	(9 + 5) * ((2 + 7) / (6 - 3))
	RPN Expression:		"9 5 + 2 7 + 6 3 - / *"
	
	Infix Expression:	((8 + 4) * (6 - 2)) / (5 + 3)
	RPN Expression:		"8 4 + 6 2 - * 5 3 + /"
*/
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : incorrect number of arguments" << std::endl;
		return (1);
	}
	try
	{
		RPN	rpn(static_cast<const char*>(av[1]));
		rpn.evaluate();
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
