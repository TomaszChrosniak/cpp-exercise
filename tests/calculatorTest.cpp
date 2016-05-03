/*! \file calculatorTest.cpp
\brief This file holds all of the tests within the CalculatorTest fixture.
*/
#include "calculatorTest.h"

Calculator* CalculatorTest::calc;

void CalculatorTest::SetUpTestCase()
{
	
}

void CalculatorTest::TearDownTestCase()
{
	
}

void CalculatorTest::SetUp()
{
	calc = new Calculator();
}

void CalculatorTest::TearDown()
{
	delete calc;
	calc = NULL;
}

void CalculatorTest::createNewCalculator(const double &initialValue)
{
	delete calc;
	calc = new Calculator(initialValue);
}

/*! \brief Tests if the calculator holds the given value. */
TEST_F(CalculatorTest, givenInitialValueCalculatorHoldsValue)
{
	double value = 0.0;
	ASSERT_DOUBLE_EQ(value, calc->getCurrentTotal());
	CalculatorTest::createNewCalculator(value = 0.49);
	ASSERT_DOUBLE_EQ(value, calc->getCurrentTotal());
}

/*! \brief Tests if the calculator correctly sums. */
TEST_F(CalculatorTest, givenInitialValueWhenAddingValueCalculatorCorrectlySums)
{
	double valueAdded = 3.78, runningTotal = valueAdded + calc->getCurrentTotal();
	ASSERT_DOUBLE_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = 0.45);
	ASSERT_DOUBLE_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = -0.21);
	ASSERT_DOUBLE_EQ(runningTotal, calc->addValue(valueAdded));
}

/*! \brief Tests if the calculator correctly sums. */
TEST_F(CalculatorTest, givenInitialValueWhenAddingValueCalculatorCorrectlySumsInts)
{
	int valueAdded = 3, runningTotal = valueAdded + (int)calc->getCurrentTotal();
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = 1);
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = -4);
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
}

/*! \brief Tests if the calculator correctly subtracts. */
TEST_F(CalculatorTest, givenInitialValueWhenSubtractingValueCalculatorCorrectlySubtracts)
{
	double valueSubtracted = 3.78, runningTotal = calc->getCurrentTotal() - valueSubtracted;
	ASSERT_DOUBLE_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = 0.45);
	ASSERT_DOUBLE_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = -0.21);
	ASSERT_DOUBLE_EQ(runningTotal, calc->subtractValue(valueSubtracted));
}

/*! \brief Tests if the calculator correctly subtracts. */
TEST_F(CalculatorTest, givenInitialValueWhenSubtractingValueCalculatorCorrectlySubtractsInts)
{
	int valueSubtracted = 3, runningTotal = calc->getCurrentTotal() - valueSubtracted;
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = 1);
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = -4);
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
}

/*! \brief Tests if the calculator correctly multiplies. */
TEST_F(CalculatorTest, givenInitialValueWhenMultiplyingValueCalculatorCorrectlyMultiplies)
{
	double factor = 3.78, runningTotal = calc->addValue(1.0) * factor;
	ASSERT_DOUBLE_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = 0.45);
	ASSERT_DOUBLE_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = -0.21);
	ASSERT_DOUBLE_EQ(runningTotal, calc->multiplyBy(factor));
}

/*! \brief Tests if the calculator correctly multiplies. */
TEST_F(CalculatorTest, givenInitialValueWhenMultiplyingValueCalculatorCorrectlyMultipliesInts)
{
	int factor = 3, runningTotal = calc->addValue(1) * factor;
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = 1);
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = -4);
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
}

/*! \brief Tests if the calculator correctly multiplies by 0. */
TEST_F(CalculatorTest, givenInitialZeroAsValueWhenMultiplyingValueCalculatorCorrectlyMultipliesBy0)
{
	ASSERT_DOUBLE_EQ(0, calc->multiplyBy(0));
	ASSERT_DOUBLE_EQ(0, calc->multiplyBy(1.0));
	ASSERT_DOUBLE_EQ(0, calc->multiplyBy(4));
	ASSERT_DOUBLE_EQ(0, calc->multiplyBy(-0.25));
}

/*! \brief Tests if the calculator correctly divides. */
TEST_F(CalculatorTest, givenInitialValueWhenDividingValueCalculatorCorrectlyDivides)
{
	double divisor = 3.78, runningTotal = calc->addValue(1.0) / divisor;
	ASSERT_DOUBLE_EQ(runningTotal, calc->divideBy(divisor));
	runningTotal /= (divisor = 0.45);
	ASSERT_DOUBLE_EQ(runningTotal, calc->divideBy(divisor));
	runningTotal /= (divisor = -0.21);
	ASSERT_DOUBLE_EQ(runningTotal, calc->divideBy(divisor));
}

/*! \brief Tests if the calculator throws exception when dividing by zero. */
TEST_F(CalculatorTest, givenInitialValueWhenDividingByZeroCalculatorThrowsAnException)
{
	CalculatorTest::createNewCalculator(4.506);
	ASSERT_THROW(calc->divideBy(0), Calculator::DivisionByZeroException);
	ASSERT_NO_THROW(calc->divideBy(3));
}

/*! \brief Tests if the calculator correctly gives the previous totals before the last operation. */
TEST_F(CalculatorTest, givenInitialValueAfterPerformingOperationsCalculatorHoldsItsPreviousValue)
{
	double previousTotal = calc->getCurrentTotal(),
		runningTotal = calc->addValue(3.78);
	ASSERT_DOUBLE_EQ(previousTotal, calc->getPreviousTotal());
	previousTotal = runningTotal;
	runningTotal = calc->subtractValue(0.5);
	ASSERT_DOUBLE_EQ(previousTotal, calc->getPreviousTotal());
	previousTotal = runningTotal;
	runningTotal = calc->multiplyBy(1.2);
	ASSERT_DOUBLE_EQ(previousTotal, calc->getPreviousTotal());
	previousTotal = runningTotal;
	runningTotal = calc->divideBy(3);
	ASSERT_DOUBLE_EQ(previousTotal, calc->getPreviousTotal());
}

/*! \brief Tests if the calculator reverts to the correct value after dividing by zero. */
TEST_F(CalculatorTest, givenInitialValueAfterPerformingOperationsCalculatorHoldsItsPreviousValueWhenDividingByZero)
{
	double runningTotal = calc->addValue(3.78),
		previousTotal = runningTotal;
	ASSERT_ANY_THROW(calc->divideBy(0.0));
	ASSERT_DOUBLE_EQ(previousTotal, calc->getPreviousTotal());
}

/*! \brief Tests if the calculator reverts to the correct value after undoing one of many operations. */
TEST_F(CalculatorTest, afterPerformingOperationsAndUndoingOneTheCurrentTotalIsCorrect)
{
	double runningTotal = calc->addValue(3.78),
		previousTotal = runningTotal,
		operationValue = 4.21;
	runningTotal *= operationValue;
	ASSERT_DOUBLE_EQ(runningTotal, calc->multiplyBy(operationValue));
	ASSERT_DOUBLE_EQ(previousTotal, calc->getPreviousTotal());
	ASSERT_NE(previousTotal, calc->getCurrentTotal());
	calc->undo();
	ASSERT_DOUBLE_EQ(previousTotal, calc->getCurrentTotal());
}

/*! \brief Tests if the calculator correctly undoes consecutive operations. */
TEST_F(CalculatorTest, givenInitialValueAfterPerformingOperationsCorrectlyUndoes)
{
	double operation1, operation2, operation3, operation4,
		previousTotal = calc->getCurrentTotal(),
		runningTotal = calc->addValue(operation1 = 3.78);
	runningTotal = calc->subtractValue(operation2 = 0.5);
	runningTotal = calc->multiplyBy(operation3 = 1.2);
	runningTotal = calc->divideBy(operation4 = 3);
	ASSERT_DOUBLE_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal *= operation4;
	ASSERT_DOUBLE_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal /= operation3;
	ASSERT_DOUBLE_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal += operation2;
	ASSERT_DOUBLE_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal -= operation1;
	ASSERT_DOUBLE_EQ(runningTotal, calc->getCurrentTotal());
}

/*! \brief Tests if the calculator handles undoing, after no operations have been performed. */
TEST_F(CalculatorTest, givenInitialValueWhenNoOperationsPerformedUndoDoesNothing)
{
	double runningTotal = 2.48;
	CalculatorTest::createNewCalculator(runningTotal);
	ASSERT_DOUBLE_EQ(runningTotal, calc->undo());
	ASSERT_DOUBLE_EQ(runningTotal, calc->undo());
	ASSERT_DOUBLE_EQ(runningTotal, calc->undo());
	ASSERT_DOUBLE_EQ(runningTotal, calc->undo());
	ASSERT_DOUBLE_EQ(runningTotal, calc->undo());
}

/*! \brief Tests if the calculator correctly undoes consecutive operations with a division by zero among them. */
TEST_F(CalculatorTest, givenInitialValueAfterPerformingOperationsReturnsCorrectString)
{
	calc->addValue(3.78);
	calc->subtractValue(0.5);
	calc->multiplyBy(1.2);
	ASSERT_ANY_THROW(calc->divideBy(0));
	calc->divideBy(3);
	ASSERT_EQ("0\n+3.78\n-0.5\n*1.2\n/3\n", calc->getOperationsString());
	calc->undo();
	ASSERT_EQ("0\n+3.78\n-0.5\n*1.2\n", calc->getOperationsString());
	calc->undo();
	ASSERT_EQ("0\n+3.78\n-0.5\n*1.2\n", calc->getOperationsString());
	calc->undo();
	ASSERT_EQ("0\n+3.78\n-0.5\n", calc->getOperationsString());
	calc->undo();
	ASSERT_EQ("0\n+3.78\n", calc->getOperationsString());
	calc->undo();
	ASSERT_EQ("0\n", calc->getOperationsString());
	calc->undo();
	ASSERT_EQ("0\n", calc->getOperationsString());
	calc->undo();
}

/*! \brief Tests if the calculator correctly resets. */
TEST_F(CalculatorTest, afterPerformingOperationsWhenClearIssuedCalculatorCleared)
{
	calc->addValue(3.78);
	calc->subtractValue(0.5);
	calc->multiplyBy(1.2);
	ASSERT_ANY_THROW(calc->divideBy(0));
	calc->divideBy(3);
	ASSERT_EQ("0\n+3.78\n-0.5\n*1.2\n/3\n", calc->getOperationsString());
	ASSERT_DOUBLE_EQ(((3.78 - 0.5)*1.2 / 3), calc->getCurrentTotal());
	calc->clear();
	ASSERT_EQ("0\n", calc->getOperationsString());
	ASSERT_DOUBLE_EQ(0.0, calc->getCurrentTotal());
	ASSERT_DOUBLE_EQ(0.0, calc->getPreviousTotal());
}

/*! \brief Tests if the calculator correctly returns the current value as previous, when no operations have been performed. */
TEST_F(CalculatorTest, whenNoOperationsPerformedGetPreviousValueReturnsCurrentValue)
{
	CalculatorTest::createNewCalculator(12.456);
	ASSERT_DOUBLE_EQ(12.456, calc->getPreviousTotal());
}
