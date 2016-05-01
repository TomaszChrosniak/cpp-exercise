#include <Calculator.h>

Calculator::Calculator()
{
	currentTotal = 0.0;
	initialStringStream.str(std::string());
	initialStringStream << currentTotal << std::endl;
	operationList.clear();
}

Calculator::Calculator(const double &initialVal)
{
	currentTotal = initialVal;
	initialStringStream.str(std::string());
	initialStringStream << currentTotal << std::endl;
	operationList.clear();
}

double Calculator::getCurrentTotal()
{
	return currentTotal;
}

double Calculator::addValue(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::SUM, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal));
}

double Calculator::subtractValue(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::SUBTRACTION, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal));
}

double Calculator::multiplyBy(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::MULTIPLICATION, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal));
}

double Calculator::divideBy(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::DIVISION, value));
	operation = &(operationList.back());
	currentTotal = operation->perform(currentTotal);
	if (!value)
		throw DivisionByZeroException();
	return currentTotal;
}

double Calculator::getPreviousTotal()
{
	if (operationList.empty())
		return currentTotal;
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

std::string Calculator::getOperationsString()
{
	std::string returnString(initialStringStream.str());
	for (auto it = operationList.begin(); it != operationList.end(); it++)
		returnString.append(it->toString());
	return returnString;
}

void Calculator::clear()
{
	currentTotal = 0.0;
	initialStringStream.str(std::string());
	initialStringStream << currentTotal << std::endl;
	operationList.clear();
}
