#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

class Operation
{
public:
	typedef enum {
		SUM,
		SUBTRACTION,
		MULTIPLICATION,
		DIVISION,
		ERROR
	} OPERATION_TYPE;

private:
	OPERATION_TYPE operationType;
	double operationValue;
	double valueBeforeOperation;

public:
	Operation(OPERATION_TYPE, double);

	double perform(const double);
	double undo(const double);
	double performReverse(const double);
	std::string toString();
};
