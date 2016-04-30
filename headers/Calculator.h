#pragma once
#include <exception>
#include <vector>

#include <Operation.h>

class Calculator
{
private:
	double currentTotal;

public:
	class DivisionByZeroException : public std::exception
	{
	public:
		const char* what() const
		{
			return "Division by 0.";
		}
	};

	std::vector<Operation> operationList;

	Calculator();
	
	Calculator(double initialValue);

	double getCurrentTotal();

	double addValue(const double value);

	double subtractValue(const double value);

	double multiplyBy(const double value);

	double divideBy(const double value);

	double getPreviousTotal();

	double undo();
};
