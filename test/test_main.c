#include "unity_fixture.h"

static void run_all_tests(void) {RUN_TEST_GROUP(color)}

int main(int argc, const char **argv)
{
    return UnityMain(argc, argv, run_all_tests);
}