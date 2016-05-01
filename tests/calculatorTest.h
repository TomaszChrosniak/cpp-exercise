/*! \file calculatorTest.h
\brief Holds the CalculatorTest fixture class.
*/
#pragma once
#include <gtest/gtest.h>
#include <Calculator.h>

/*! \class CalculatorTest
\brief This class is a test fixture, that sets up the necessary data before performing tests of the Calculator class.
*/
class CalculatorTest : public ::testing::Test {
protected:
	// Per-test-case set-up.
	// Called before the first test in this test case.
	// Can be omitted if not needed.
	/*! \brief Performs the setup before running any of the associated tests. */
	static void SetUpTestCase();

	// Per-test-case tear-down.
	// Called after the last test in this test case.
	// Can be omitted if not needed.
	/*! \brief Performs the removal of resources after every associated test has been finished. */
	static void TearDownTestCase();

	/*! \brief Performs the setup before running each and every of the associated tests. */
	virtual void SetUp();

	/*! \brief Performs the removal of resources after any of the associated tests finish. */
	virtual void TearDown();

	/*! \brief Creates a new calculator object and initializes it with the given value
	\param[in] initialValue the initial calculator value
	*/
	static void createNewCalculator(const double &initialValue);

	static Calculator* calc; /*!< A calculator object used in the tests. */
};
