#include "Calculator.h"

Calculator::Calculator()
{
	currentValue = previousValue = 0;
}

Calculator::Calculator(double initialVal)
{
	currentValue = initialVal;
	previousValue = 0.0;
}
