/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:24:07 by suchua            #+#    #+#             */
/*   Updated: 2023/08/28 01:37:27 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__

# include <algorithm>
# include <stack>
# include <iostream>
# include <exception>

class RPN
{
	private:
		std::stack<int>	stack;
		const char		*tokens;
		void			swap2();
		void			add();
		void			sub();
		void			mul();
		void			div();
	public:
		RPN(const char *tokens);
		~RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		void	evaluate();
		int		getResult() const;

		class invalidTokensException : public std::exception
		{
			const char	*what() const throw ()
			{
				return "Error : Invalid tokens.\n";
			}
		};
};

#endif
