#include <gtest/gtest.h>
#include "calculatorTest.h"

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

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
