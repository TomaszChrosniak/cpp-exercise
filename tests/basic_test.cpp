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

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
