#include <Calculator.h>
/*! \file Calculator.cpp
\brief This file holds the definitions for the Calculator class.
 */

Calculator::Calculator() : currentTotal(0.0)
{
	initialStringStream.str(std::string());
	initialStringStream << currentTotal << std::endl;
	operationList.clear();
}

Calculator::Calculator(const Number &initialVal)
	: currentTotal(initialVal)
{
	initialStringStream.str(std::string());
	initialStringStream << currentTotal << std::endl;
	operationList.clear();
}

double Calculator::getCurrentTotal()
{
	return currentTotal.getRealPart();
}

double Calculator::addValue(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::SUM, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal)).getRealPart();
}

double Calculator::subtractValue(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::SUBTRACTION, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal)).getRealPart();
}

double Calculator::multiplyBy(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::MULTIPLICATION, value));
	operation = &(operationList.back());
	return (currentTotal = operation->perform(currentTotal)).getRealPart();
}

double Calculator::divideBy(const double &value)
{
	Operation* operation;
	operationList.push_back(Operation(Operation::OPERATION_TYPE::DIVISION, value));
	operation = &(operationList.back());
	currentTotal = operation->perform(currentTotal);
	if (!value)
		throw DivisionByZeroException();
	return currentTotal.getRealPart();
}

double Calculator::getPreviousTotal()
{
	if (operationList.empty())
		return currentTotal.getRealPart();
	return operationList.back().undo(currentTotal).getRealPart();
}

double Calculator::undo()
{
	if (operationList.empty())
		return currentTotal.getRealPart();
	currentTotal = operationList.back().undo(currentTotal);
	operationList.pop_back();
	return currentTotal.getRealPart();
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
