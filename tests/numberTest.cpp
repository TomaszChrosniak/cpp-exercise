#include "numberTest.h"

TEST(NumberTest, givenValueNumberHoldsValue)
{
	Number num(2.1, 0.4);
	ASSERT_DOUBLE_EQ(2.1, num.getRealPart());
	ASSERT_DOUBLE_EQ(0.4, num.getImaginaryPart());
	num = Number(-0.211, -1.24);
	ASSERT_DOUBLE_EQ(-0.211, num.getRealPart());
	ASSERT_DOUBLE_EQ(-1.24, num.getImaginaryPart());
}

TEST(NumberTest, givenDoubleCorrectlyConvertsToNumber)
{
	ASSERT_EQ(2.0, Number(2.0, 0));
	ASSERT_EQ(4.5, Number(4.5, 0));
	ASSERT_NE(-1.12, Number(-1.12, 0.49));
}

TEST(NumberTest, givenIntCorrectlyConvertsToNumber)
{
	ASSERT_EQ(2, Number(2, 0));
	ASSERT_EQ(4, Number(4, 0));
	ASSERT_NE(-1, Number(-1, 1));
}

TEST(NumberTest, whenAddingTwoComplexNumbersSumIsCorrect)
{
	Number one(2, 3), two(4, 1);
	ASSERT_EQ(Number(6, 4), one + two);
	one = Number(3, 5);
	two = Number(1, 2);
	ASSERT_EQ(Number(4, 7), one + two);
	one = Number(1.41, 1.09);
	two = Number(2.17, 3.12);
	ASSERT_EQ(Number(3.58, 4.21), one + two);
}

TEST(NumberTest, whenSubtractingTwoComplexNumbersDifferenceIsCorrect)
{
	Number one(2, 3), two(4, 1);
	ASSERT_EQ(Number(-2, 2), (one - two));
	one = Number(3, 5);
	two = Number(1, 2);
	ASSERT_EQ(Number(2, 3), (one - two));
	one = Number(1.41, 1.09);
	two = Number(2.17, 3.12);
	ASSERT_EQ(Number(1.41 - 2.17, 1.09 - 3.12), (one - two));
}

TEST(NumberTest, whenComparingTwoRealNumbersResultIsCorrect)
{
	Number one(1, 0), two(3, 0);
	ASSERT_EQ(false, one>two);
	ASSERT_EQ(true, one<two);
	one = Number(4, 0);
	two = Number(2, 0);
	ASSERT_EQ(true, one>two);
	ASSERT_EQ(false, one<two);
}

TEST(NumberTest, whenComparingTwoComplexNumbersResultIsUndefined)
{
	Number one(2, 3), two(4, 1);
	ASSERT_EQ(false, one>two);
	ASSERT_EQ(false, one<two);
	one = Number(1, 2);
	two = Number(1, 2); 
	ASSERT_EQ(false, one>two);
	ASSERT_EQ(false, one<two);
}

TEST(NumberTest, whenMultiplyingTwoComplexNumbersProductIsCorrect)
{
	Number one(2, 3), two(4, 1);
	ASSERT_EQ(Number(5, 14), one * two);
	one = Number(3, 5);
	two = Number(1, 2);
	ASSERT_EQ(Number(-7, 11), one * two);
	one = Number(1.41, 1.09);
	two = Number(2.17, 3.12);
	ASSERT_EQ(Number(1.41 * 2.17 - 1.09 * 3.12, 1.41 * 3.12 + 2.17 * 1.09), one * two);
}

TEST(NumberTest, whenDividingTwoComplexNumbersQuotientIsCorrect)
{
	Number one(2, 3), two(4, 1);
	double numeratorReal = (2.0 * 4.0  + 3.0),
		numeratorImaginary = (12.0 - 2.0),
		denominator = (16.0 + 1.0);
	ASSERT_EQ(Number(numeratorReal / denominator, numeratorImaginary / denominator), one / two);
	one = Number(-2.12, 1.32);
	two = Number(0.79, -3.12);
	numeratorReal = (-2.12 * 0.79 - 1.32 * 3.12);
	numeratorImaginary = (-2.12 * 3.12 + 1.32 * 0.79);
	denominator = (0.79 * 0.79 + 3.12 * 3.12);
	ASSERT_EQ(Number(numeratorReal / denominator, numeratorImaginary / denominator), one / two);
}
