#pragma once
#include <string>
#include <sstream>

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

public:
	Operation(OPERATION_TYPE, double);

	double perform(const double);
	double undo(const double);
	std::string toString();
};
