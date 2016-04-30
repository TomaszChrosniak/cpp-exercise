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
