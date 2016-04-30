#pragma once

class Calculator
{
private:
	double currentTotal, previousTotal;

public:
	Calculator();

	Calculator(double initialValue);

	double getCurrentTotal();

	double addValue(double value);
};
