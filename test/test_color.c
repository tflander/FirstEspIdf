#include "unity_fixture.h"

TEST_GROUP(color);
TEST_SETUP(color) {}
TEST_TEAR_DOWN(color) {}

TEST(color, firsttest)
{
    TEST_FAIL();
}

TEST_GROUP_RUNNER(color) {RUN_TEST_CASE(color, firsttest);}
