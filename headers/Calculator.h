#pragma once

class Calculator
{
private:
	double currentTotal, previousTotal;

public:
	Calculator();

	Calculator(double initialValue);

	double getCurrentTotal();

	double addValue(const double value);

	double subtractValue(const double value);

	double multiplyBy(const double value);

	double divideBy(const double value);
};
