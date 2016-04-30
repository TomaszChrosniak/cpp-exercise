#include <Operation.h>

Operation::Operation(Operation::OPERATION_TYPE newOperationType, double newOperationValue)
{
	operationValue = newOperationValue;
	if (!newOperationValue && newOperationType == DIVISION)
		operationType = ERROR;
	else
		operationType = newOperationType;	
}

double Operation::perform(double currentValue)
{
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
	}
}

double Operation::undo(double currentValue)
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
	}
}
