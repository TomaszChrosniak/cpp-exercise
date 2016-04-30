#include <Calculator.h>

Calculator::Calculator()
{
	currentTotal = 0.0;
	operationList.clear();
}

Calculator::Calculator(double initialVal)
{
	currentTotal = initialVal;
	operationList.clear();
}

double Calculator::getCurrentTotal()
{
	return currentTotal;
}

double Calculator::addValue(double value)
{
	Operation* operation;
	operationList.push_back(*(operation = &(Operation(Operation::OPERATION_TYPE::SUM, value))));
	return (currentTotal = operation->perform(currentTotal));
}

double Calculator::subtractValue(double value)
{
	Operation* operation;
	operationList.push_back(*(operation = &(Operation(Operation::OPERATION_TYPE::SUBTRACTION, value))));
	return (currentTotal = operation->perform(currentTotal));
}

double Calculator::multiplyBy(double value)
{
	Operation* operation;
	operationList.push_back(*(operation = &(Operation(Operation::OPERATION_TYPE::MULTIPLICATION, value))));
	return (currentTotal = operation->perform(currentTotal));
}

double Calculator::divideBy(double value)
{
	Operation* operation;
	operationList.push_back(*(operation = &(Operation(Operation::OPERATION_TYPE::DIVISION, value))));
	currentTotal = operation->perform(currentTotal);
	if (!value)
		throw DivisionByZeroException();
	return currentTotal;
}

double Calculator::getPreviousTotal()
{
	return operationList.back().undo(currentTotal);
}

double Calculator::undo()
{
	if (operationList.empty())
		return currentTotal;
	currentTotal = operationList.back().undo(currentTotal);
	operationList.pop_back();
	return currentTotal;
}
