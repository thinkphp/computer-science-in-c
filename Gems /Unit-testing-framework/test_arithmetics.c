#include "test_framework.h"

TEST(addition) {
    ASSERT_EQUAL(4, 2 + 2);
    ASSERT_EQUAL(0, -5 + 5);
    ASSERT_EQUAL(-5, -1 * 5);
}

TEST(factorial) {
    ASSERT_EQUAL(120, 1*2*3*4*5);
    ASSERT_EQUAL(-2, 1*2);
}

TEST(strings) {
    char str[] = "hello";
    ASSERT_STR_EQUAL("hello", str);
}

int main() {
    RUN_TEST(addition);
    RUN_TEST(factorial);
    RUN_TEST(strings);
    return 0;
}
