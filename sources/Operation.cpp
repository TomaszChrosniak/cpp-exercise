#include <Operation.h>

Operation::Operation(Operation::OPERATION_TYPE newOperationType, double newOperationValue)
{
	valueBeforeOperation = 0.0;
	operationValue = newOperationValue;
	if (!newOperationValue && newOperationType == DIVISION)
		operationType = ERROR;
	else
		operationType = newOperationType;	
}

double Operation::perform(double currentValue)
{
	valueBeforeOperation = currentValue;
	switch (operationType)
	{
	case SUM:
		return currentValue + operationValue;
	case SUBTRACTION:
		return currentValue - operationValue;
	case MULTIPLICATION:
		return currentValue * operationValue;
	case DIVISION:
		return currentValue / operationValue;
	case ERROR:
		return currentValue;
	default:
		return currentValue;
	}
}

double Operation::undo(double currentValue)
{
	return valueBeforeOperation;
}

double Operation::performReverse(double currentValue)
{
	switch (operationType)
	{
	case SUM:
		return currentValue - operationValue;
	case SUBTRACTION:
		return currentValue + operationValue;
	case MULTIPLICATION:
		return currentValue / operationValue;
	case DIVISION:
		return currentValue * operationValue;
	case ERROR:
		return currentValue;
	default:
		return currentValue;
	}
}

std::string Operation::toString()
{
	std::stringstream outputStream;
	outputStream << std::setprecision(std::numeric_limits<double>::digits10 + 1);
	switch (operationType)
	{
	case SUM:
		outputStream << "+" << operationValue << std::endl;
		return outputStream.str();
	case SUBTRACTION:
		outputStream << "-" << operationValue << std::endl;
		return outputStream.str();
	case MULTIPLICATION:
		outputStream << "*" << operationValue << std::endl;
		return outputStream.str();
	case DIVISION:
		outputStream << "/" << operationValue << std::endl;
		return outputStream.str();
	case ERROR:
		return "";
	default:
		return "";
	}
}
