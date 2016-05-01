#pragma once
#include <exception>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

#include <Operation.h>

class Calculator
{
private:
	double currentTotal;

	std::stringstream initialStringStream;

public:
	class DivisionByZeroException : public std::exception
	{
	public:
		virtual const char* what() const throw()
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

	std::string getOperationsString();

	void clear();
};
