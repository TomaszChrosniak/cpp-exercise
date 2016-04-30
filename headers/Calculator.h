#pragma once
#include <exception>

class Calculator
{
private:
	double currentTotal, previousTotal;

public:
	class DivisionByZeroException : public std::exception
	{
	public:
		const char* what() const
		{
			return "Division by 0.";
		}
	};

	Calculator();

	Calculator(double initialValue);

	double getCurrentTotal();

	double addValue(const double value);

	double subtractValue(const double value);

	double multiplyBy(const double value);

	double divideBy(const double value);
};
