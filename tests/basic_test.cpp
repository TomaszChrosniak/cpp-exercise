#include <gtest/gtest.h>
#include "calculatorTest.h"

TEST_F(CalculatorTest, givenInitialValueCalculatorHoldsValue)
{
	double value = 0.0;
	ASSERT_EQ(value, calc->getCurrentTotal());
	CalculatorTest::createNewCalculator(value = 0.49);
	ASSERT_EQ(value, calc->getCurrentTotal());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
