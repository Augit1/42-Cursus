#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <stdexcept>

class RPN
{
	private:
		std::stack<int>	_stack;
		bool	isOperator(const std::string& token)	const;
		bool	isValidRPN(const std::string& expression);
		int		applyOperator(const std::string& op, int a, int b)	const;

	public:
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);
		~RPN();

		int	calculate(const std::string& expression);
};

#endif // RPN_HPP
