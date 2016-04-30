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

void CalculatorTest::createNewCalculator(double initialValue)
{
	delete calc;
	calc = new Calculator(initialValue);
}


TEST_F(CalculatorTest, givenInitialValueCalculatorHoldsValue)
{
	double value = 0.0;
	ASSERT_EQ(value, calc->getCurrentTotal());
	CalculatorTest::createNewCalculator(value = 0.49);
	ASSERT_EQ(value, calc->getCurrentTotal());
}

TEST_F(CalculatorTest, givenInitialValueWhenAddingValueCalculatorCorrectlySums)
{
	double valueAdded = 3.78, runningTotal = valueAdded + calc->getCurrentTotal();
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = 0.45);
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = -0.21);
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
}

TEST_F(CalculatorTest, givenInitialValueWhenAddingValueCalculatorCorrectlySumsInts)
{
	int valueAdded = 3, runningTotal = valueAdded + (int)calc->getCurrentTotal();
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = 1);
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
	runningTotal += (valueAdded = -4);
	ASSERT_EQ(runningTotal, calc->addValue(valueAdded));
}

TEST_F(CalculatorTest, givenInitialValueWhenSubtractingValueCalculatorCorrectlySubtracts)
{
	double valueSubtracted = 3.78, runningTotal = calc->getCurrentTotal() - valueSubtracted;
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = 0.45);
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = -0.21);
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
}

TEST_F(CalculatorTest, givenInitialValueWhenSubtractingValueCalculatorCorrectlySubtractsInts)
{
	int valueSubtracted = 3, runningTotal = calc->getCurrentTotal() - valueSubtracted;
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = 1);
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
	runningTotal -= (valueSubtracted = -4);
	ASSERT_EQ(runningTotal, calc->subtractValue(valueSubtracted));
}

TEST_F(CalculatorTest, givenInitialValueWhenMultiplyingValueCalculatorCorrectlyMultiplies)
{
	double factor = 3.78, runningTotal = calc->addValue(1.0) * factor;
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = 0.45);
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = -0.21);
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
}

TEST_F(CalculatorTest, givenInitialValueWhenMultiplyingValueCalculatorCorrectlyMultipliesInts)
{
	int factor = 3, runningTotal = calc->addValue(1) * factor;
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = 1);
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
	runningTotal *= (factor = -4);
	ASSERT_EQ(runningTotal, calc->multiplyBy(factor));
}

TEST_F(CalculatorTest, givenInitialZeroAsValueWhenMultiplyingValueCalculatorCorrectlyMultipliesBy0)
{
	ASSERT_EQ(0, calc->multiplyBy(0));
	ASSERT_EQ(0, calc->multiplyBy(1.0));
	ASSERT_EQ(0, calc->multiplyBy(4));
	ASSERT_EQ(0, calc->multiplyBy(-0.25));
}

TEST_F(CalculatorTest, givenInitialValueWhenDividingValueCalculatorCorrectlyDivides)
{
	double divisor = 3.78, runningTotal = calc->addValue(1.0) / divisor;
	ASSERT_EQ(runningTotal, calc->divideBy(divisor));
	runningTotal /= (divisor = 0.45);
	ASSERT_EQ(runningTotal, calc->divideBy(divisor));
	runningTotal /= (divisor = -0.21);
	ASSERT_EQ(runningTotal, calc->divideBy(divisor));
}

TEST_F(CalculatorTest, givenInitialValueWhenDividingByZeroCalculatorThrowsAnException)
{
	CalculatorTest::createNewCalculator(4.506);
	ASSERT_THROW(calc->divideBy(0), Calculator::DivisionByZeroException);
	ASSERT_NO_THROW(calc->divideBy(3));
}

TEST_F(CalculatorTest, givenInitialValueAfterPerformingOperationsCalculatorHoldsItsPreviousValue)
{
	double previousTotal = calc->getCurrentTotal(),
		runningTotal = calc->addValue(3.78);
	ASSERT_EQ(previousTotal, calc->getPreviousTotal());
	previousTotal = runningTotal;
	runningTotal = calc->subtractValue(0.5);
	ASSERT_EQ(previousTotal, calc->getPreviousTotal());
	previousTotal = runningTotal;
	runningTotal = calc->multiplyBy(1.2);
	ASSERT_EQ(previousTotal, calc->getPreviousTotal());
	previousTotal = runningTotal;
	runningTotal = calc->divideBy(3);
	ASSERT_EQ(previousTotal, calc->getPreviousTotal());
}

TEST_F(CalculatorTest, givenInitialValueAfterPerformingOperationsCalculatorHoldsItsPreviousValueWhenDividingByZero)
{
	double runningTotal = calc->addValue(3.78),
		previousTotal = runningTotal;
	ASSERT_ANY_THROW(calc->divideBy(0.0));
	ASSERT_EQ(previousTotal, calc->getPreviousTotal());
}

TEST_F(CalculatorTest, afterPerformingOperationsAndUndoingOneTheCurrentTotalIsCorrect)
{
	double runningTotal = calc->addValue(3.78),
		previousTotal = runningTotal,
		operationValue = 4.21;
	runningTotal *= operationValue;
	ASSERT_EQ(runningTotal, calc->multiplyBy(operationValue));
	ASSERT_EQ(previousTotal, calc->getPreviousTotal());
	ASSERT_NE(previousTotal, calc->getCurrentTotal());
	calc->undo();
	ASSERT_EQ(previousTotal, calc->getCurrentTotal());
}

TEST_F(CalculatorTest, givenInitialValueAfterPerformingOperationsCorrectlyUndoes)
{
	double operation1, operation2, operation3, operation4,
		previousTotal = calc->getCurrentTotal(),
		runningTotal = calc->addValue(operation1 = 3.78);
	runningTotal = calc->subtractValue(operation2 = 0.5);
	runningTotal = calc->multiplyBy(operation3 = 1.2);
	runningTotal = calc->divideBy(operation4 = 3);
	ASSERT_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal *= operation4;
	ASSERT_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal /= operation3;
	ASSERT_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal += operation2;
	ASSERT_EQ(runningTotal, calc->getCurrentTotal());
	calc->undo();
	runningTotal -= operation1;
	ASSERT_EQ(runningTotal, calc->getCurrentTotal());
}

TEST_F(CalculatorTest, givenInitialValueWhenNoOperationsPerformedUndoDoesNothing)
{
	double runningTotal = 2.48;
	CalculatorTest::createNewCalculator(runningTotal);
	ASSERT_EQ(runningTotal, calc->undo());
	ASSERT_EQ(runningTotal, calc->undo());
	ASSERT_EQ(runningTotal, calc->undo());
	ASSERT_EQ(runningTotal, calc->undo());
	ASSERT_EQ(runningTotal, calc->undo());
}

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
