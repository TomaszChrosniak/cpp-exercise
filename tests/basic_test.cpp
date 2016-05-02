#include <gtest/gtest.h>
#include "calculatorTest.h"
#include "operationTest.h"
#include "numberTest.h"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
