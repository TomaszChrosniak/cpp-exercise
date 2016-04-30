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
	previousTotal = currentTotal;
	return (currentTotal += value);
}

double Calculator::subtractValue(double value)
{
	previousTotal = currentTotal;
	return (currentTotal -= value);
}

double Calculator::multiplyBy(double value)
{
	previousTotal = currentTotal;
	return (currentTotal *= value);
}

double Calculator::divideBy(double value)
{
	previousTotal = currentTotal;
	if (!value)
		throw DivisionByZeroException();
	return (currentTotal /= value);
}

double Calculator::getPreviousTotal()
{
	return previousTotal;
}
