#include "test_framework.h"

// Euclidean algorithm implementation
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

TEST(euclidean) {
    // Normal cases
    ASSERT_FUNC(6, gcd, 48, 18);    // gcd(48,18) = 6
    ASSERT_FUNC(1, gcd, 17, 13);    // Coprime numbers
    ASSERT_FUNC(21, gcd, 252, 105); // Larger numbers

    // Edge cases
    ASSERT_FUNC(5, gcd, 5, 0);      // One number is 0
    ASSERT_FUNC(7, gcd, 7, 7);      // Equal numbers
    ASSERT_FUNC(-3, gcd, -9, -6);    // Negative numbers
}

int main() {
    RUN_TEST(euclidean);
    return 0;
}
