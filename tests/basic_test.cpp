#include <gtest/gtest.h>

TEST(ExampleTest, IsTruthful)
{
	EXPECT_TRUE(true);
}

TEST(ExampleTest, IsFalsey)
{
	EXPECT_FALSE(false);
}

TEST(ExampleTest, ThisOneFailsFixMe)
{
	EXPECT_TRUE(false);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
