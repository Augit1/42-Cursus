#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

bool	RPN::isOperator(const std::string& token)	const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool	RPN::isValidRPN(const std::string& expression)
{
	std::istringstream	ss(expression);
	std::string			token;
	int					opCount = 0;

	while (ss >> token)
	{
		if (std::isdigit(token[0]) && token.size() == 1)
			opCount++;
		else if (isOperator(token))
		{
			if (opCount < 2) return false;
			opCount--;
		}
		else return false;
	}
	return opCount == 1;
}

int		RPN::applyOperator(const std::string& op, int a, int b)	const
{
	if (op == "+") return a + b;
	if (op == "-") return a - b;
	if (op == "*") return a * b;
	if (op == "/")
	{
		if (b == 0) throw std::runtime_error("Error: Division by zero.");
		return a / b;
	}
	throw std::runtime_error("Error: Unknown operator.");
}

int		RPN::calculate(const std::string& expression)
{
	std::istringstream	ss(expression);
	std::string			token;
	if (!isValidRPN(expression)) throw std::runtime_error("Error: Invalid RPN expression.");
	while (ss >> token)
	{
		if (std::isdigit(token[0]))
			_stack.push(token[0] - '0');
		else if (isOperator(token))
		{
			int	b = _stack.top();
			_stack.pop();
			int	a = _stack.top();
			_stack.pop();
			int	result = applyOperator(token, a, b);
			_stack.push(result);
		}
		else throw std::runtime_error("Error: invalid token.");
	}
	if (_stack.size() != 1) throw std::runtime_error("Error: too many operand!");
	return _stack.top();
}
