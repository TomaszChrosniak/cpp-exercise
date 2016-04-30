#pragma once
#include <gtest\gtest.h>
#include "../Calculator.h"

class CalculatorTest : public ::testing::Test {
protected:
	// Per-test-case set-up.
	// Called before the first test in this test case.
	// Can be omitted if not needed.
	static void SetUpTestCase();

	// Per-test-case tear-down.
	// Called after the last test in this test case.
	// Can be omitted if not needed.
	static void TearDownTestCase();

	// You can define per-test set-up and tear-down logic as usual.
	virtual void SetUp();

	virtual void TearDown();

	static Calculator* calc;
};
