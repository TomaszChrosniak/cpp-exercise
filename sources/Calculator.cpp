#include <Calculator.h>
/*! \file Calculator.cpp
\brief This file holds the definitions for the Calculator class.
 */

Calculator::Calculator() : currentTotal(0.0)
{
	currentTotal = 0.0;
	initialStringStream.str(std::string());
	initialStringStream << currentTotal << std::endl;
	operationList.clear();
}

Calculator::Calculator(const Number &initialVal) : currentTotal(0,0)
{
	currentTotal = initialVal;
	initialStringStream.str(std::string());
	initialStringStream << currentTotal << std::endl;
	operationList.clear();
}

Number Calculator::getCurrentTotal()
{
	return currentTotal;
}

Number Calculator::addValue(const Number &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::SUM, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal));
}

Number Calculator::subtractValue(const Number &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::SUBTRACTION, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal));
}

Number Calculator::multiplyBy(const Number &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::MULTIPLICATION, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal));
}

Number Calculator::divideBy(const Number &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::DIVISION, value));
	operation = &(operationList.back());
	currentTotal = operation->perform(currentTotal);
	if (!value)
		throw DivisionByZeroException();
	return currentTotal;
}

Number Calculator::getPreviousTotal()
{
	if (operationList.empty())
		return currentTotal;
	return operationList.back().undo(currentTotal);
}

Number Calculator::undo()
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
