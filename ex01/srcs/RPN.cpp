/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:26:35 by suchua            #+#    #+#             */
/*   Updated: 2023/08/30 19:30:43 by suchua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isNum(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isOp(char c)
{
	if (c == '+' || c == '-')
		return (true);
	if (c == '*' || c == '/')
		return (true);
	return (false);
}

bool	invalidTokens(const char *t)
{
	for (int i = 0; t[i]; i++)
	{
		if (isOp(t[i]) || isspace(t[i]))
			continue ;
		if (t[i] < '0' || t[i] > '9')
			return (false);
	}
	return (true);
}

RPN::RPN(const char *tokens) : tokens(tokens)
{
	if (!invalidTokens(this->tokens))
		throw invalidTokensException();
}

RPN::~RPN(){}

RPN::RPN(const RPN& other) :
tokens(other.tokens)
{
	if (this == &other)
		return ;
	this->stack = other.stack;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this == &other)
		return (*this);
	this->stack = other.stack;
	this->tokens = other.tokens;
	return (*this);
}

void	RPN::add()
{
	int	top;

	top = stack.top();
	stack.pop();
	top += stack.top();
	stack.pop();
	stack.push(top);
}

void	RPN::sub()
{
	int	top;

	top = stack.top();
	stack.pop();
	top -= stack.top();
	stack.pop();
	stack.push(top);
}

void	RPN::mul()
{
	int	top;

	top = stack.top();
	stack.pop();
	top *= stack.top();
	stack.pop();
	stack.push(top);
}

void	RPN::div()
{
	int	top;

	top = stack.top();
	stack.pop();
	top /= stack.top();
	stack.pop();
	stack.push(top);
}

void	RPN::swap2()
{
	if (stack.size() < 2)
		throw invalidTokensException();
	int	t1;
	int	t2;

	t1 = stack.top();
	stack.pop();
	t2 = stack.top();
	stack.pop();
	stack.push(t1);
	stack.push(t2);
}

void	RPN::evaluate()
{
	int	i = 0;

	while (tokens[i])
	{
		if (isNum(tokens[i]))
			stack.push(std::atoi(&tokens[i]));
		while (tokens[i] && isNum(tokens[i]))
			++i;
		while (tokens[i] && isspace(tokens[i]))
			++i;
		if (tokens[i] && isOp(tokens[i]))
		{
			swap2();
			if (tokens[i] == '+')
				add();
			else if (tokens[i] == '-')
				sub();
			else if (tokens[i] == '*')
				mul();
			else
				div();
			++i;
		}
	}
	if (stack.size() != 1)
		throw invalidTokensException();
}

int	RPN::getResult() const
{
	return (stack.top());
}
