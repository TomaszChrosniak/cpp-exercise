#include <Calculator.h>

Calculator::Calculator()
{
	currentTotal = previousTotal = 0;
}

Calculator::Calculator(double initialVal)
{
	currentTotal = initialVal;
	previousTotal = 0.0;
}

double Calculator::getCurrentTotal()
{
	return currentTotal;
}

double Calculator::addValue(double value)
{
	return (currentTotal += value);
}
