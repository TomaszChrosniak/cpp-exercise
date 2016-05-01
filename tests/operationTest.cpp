/*! \file operationTest.cpp
\brief This file holds all of the tests within the CalculatorTest fixture.
*/
#include "operationTest.h"

/*! \brief Tests if the operation correctly adds values. */
TEST(OperationTest, givenZeroValueOperationProperlySums)
{
	double runningTotal = 1.12, operationValue = 0.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::SUM, operationValue);
	ASSERT_EQ(runningTotal + operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal += operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::SUM, operationValue = -0.11);
	ASSERT_EQ(runningTotal + operationValue, oper->perform(runningTotal));
	delete oper;
}

/*! \brief Tests if the operation correctly undoes addition. */
TEST(OperationTest, givenZeroValueOperationProperlyUndoesSum)
{
	double runningTotal = 1.12, operationValue = 0.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::SUM, operationValue);
	ASSERT_EQ(runningTotal + operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal += operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::SUM, operationValue = -0.11);
	ASSERT_EQ(runningTotal + operationValue, oper->perform(runningTotal));
	ASSERT_EQ(runningTotal, oper->undo(runningTotal + operationValue));
	delete oper;
}

/*! \brief Tests if the operation correctly subtracts values. */
TEST(OperationTest, givenZeroValueOperationProperlySubtracts)
{
	double runningTotal = -0.01, operationValue = 0.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::SUBTRACTION, operationValue);
	ASSERT_EQ(runningTotal - operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal -= operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::SUBTRACTION, operationValue = -0.11);
	ASSERT_EQ(runningTotal - operationValue, oper->perform(runningTotal));
	delete oper;
}

/*! \brief Tests if the operation correctly undoes subtraction. */
TEST(OperationTest, givenZeroValueOperationProperlyUndoesSubtraction)
{
	double runningTotal = -0.01, operationValue = 0.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::SUBTRACTION, operationValue);
	ASSERT_EQ(runningTotal - operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal -= operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::SUBTRACTION, operationValue = -0.11);
	ASSERT_EQ(runningTotal - operationValue, oper->perform(runningTotal));
	ASSERT_EQ(runningTotal, oper->undo(runningTotal - operationValue));
	delete oper;
}

/*! \brief Tests if the operation correctly multiplies by a value. */
TEST(OperationTest, givenZeroValueOperationProperlyMultiplies)
{
	double runningTotal = 1.91, operationValue = 1.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::MULTIPLICATION, operationValue);
	ASSERT_EQ(runningTotal * operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal *= operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::MULTIPLICATION, operationValue = -0.11);
	ASSERT_EQ(runningTotal * operationValue, oper->perform(runningTotal));
	delete oper;
}

/*! \brief Tests if the operation correctly undoes multiplication. */
TEST(OperationTest, givenZeroValueOperationProperlyUndoesMultiplication)
{
	double runningTotal = 1.91, operationValue = 1.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::MULTIPLICATION, operationValue);
	ASSERT_EQ(runningTotal * operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal *= operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::MULTIPLICATION, operationValue = -0.11);
	ASSERT_EQ(runningTotal * operationValue, oper->perform(runningTotal));
	ASSERT_EQ(runningTotal, oper->undo(runningTotal * operationValue));
	delete oper;
}

/*! \brief Tests if the operation correctly divides by a value. */
TEST(OperationTest, givenZeroValueOperationProperlyDivides)
{
	double runningTotal = -10.21, operationValue = 2.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::DIVISION, operationValue);
	ASSERT_EQ(runningTotal / operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal /= operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::DIVISION, operationValue = -0.709);
	ASSERT_EQ(runningTotal / operationValue, oper->perform(runningTotal));
	delete oper;
}

/*! \brief Tests if the operation correctly undoes division. */
TEST(OperationTest, givenZeroValueOperationProperlyUndoesDivision)
{
	double runningTotal = -10.21, operationValue = 2.49;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::DIVISION, operationValue);
	ASSERT_EQ(runningTotal / operationValue, oper->perform(runningTotal));
	delete oper;
	runningTotal /= operationValue;
	oper = new Operation(Operation::OPERATION_TYPE::DIVISION, operationValue = -0.709);
	ASSERT_EQ(runningTotal / operationValue, oper->perform(runningTotal));
	ASSERT_EQ(runningTotal, oper->undo(runningTotal / operationValue));
	delete oper;
}

/*! \brief Tests if the operation returns the given value when trying to divide by zero. */
TEST(OperationTest, givenZeroValueOperationIgnoresDividingByZero)
{
	double runningTotal = -10.21, operationValue = 0.0;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::DIVISION, operationValue);
	ASSERT_EQ(runningTotal, oper->perform(runningTotal));
	delete oper;
}

/*! \brief Tests if the operation correctly undoes division by zero. */
TEST(OperationTest, givenZeroValueOperationProperlyUndoesDivisionByZero)
{
	double runningTotal = -10.21, operationValue = 0.0;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::DIVISION, operationValue);
	ASSERT_EQ(runningTotal, oper->perform(runningTotal));
	ASSERT_EQ(runningTotal, oper->undo(runningTotal));
	delete oper;
}

/*! \brief Tests if the operation correctly converts the opreator and value to string. */
TEST(OperationTest, givenAnOperationWhenConvertingToStringBehavesCorrectly)
{
	double operationValue = 4.215;
	Operation* oper = new Operation(Operation::OPERATION_TYPE::DIVISION, operationValue);
	ASSERT_EQ("/4.215\n", oper->toString());
	delete oper;
	oper = new Operation(Operation::OPERATION_TYPE::MULTIPLICATION, operationValue = 2.01);
	ASSERT_EQ("*2.01\n", oper->toString());
	delete oper;
	oper = new Operation(Operation::OPERATION_TYPE::SUM, 0.00015);
	ASSERT_EQ("+0.00015\n", oper->toString());
	delete oper;
	oper = new Operation(Operation::OPERATION_TYPE::SUBTRACTION, 0.0001);
	ASSERT_EQ("-0.0001\n", oper->toString());
	delete oper;
	oper = new Operation(Operation::OPERATION_TYPE::DIVISION, 0.0000);
	ASSERT_EQ("", oper->toString());
	delete oper;
}
