#ifndef TEST_FRAMEWORK_H
#define TEST_FRAMEWORK_H

#include <stdio.h>
#include <string.h>

// Global variable to track test status
static int test_failed = 0;

#define TEST(name) void test_##name()

#define RUN_TEST(name) do { \
    test_failed = 0; \
    printf("Running test_%s... ", #name); \
    test_##name(); \
    if (!test_failed) { \
        printf("PASSED\n"); \
    } \
} while (0)

#define ASSERT(condition) do { \
    if (!(condition)) { \
        printf("FAILED\n"); \
        printf("Assertion failed at %s:%d\n", __FILE__, __LINE__); \
        test_failed = 1; \
        return; \
    } \
} while (0)

#define ASSERT_EQUAL(expected, actual) do { \
    if ((expected) != (actual)) { \
        printf("FAILED\n"); \
        printf("Expected %d but got %d at %s:%d\n", \
            (expected), (actual), __FILE__, __LINE__); \
        test_failed = 1; \
        return; \
    } \
} while (0)

#define ASSERT_STR_EQUAL(expected, actual) do { \
    if (strcmp((expected), (actual)) != 0) { \
        printf("FAILED\n"); \
        printf("Expected \"%s\" but got \"%s\" at %s:%d\n", \
            (expected), (actual), __FILE__, __LINE__); \
        test_failed = 1; \
        return; \
    } \
} while (0)

#define ASSERT_FUNC(expected, func, ...) do { \
    int result = func(__VA_ARGS__); \
    if (result != expected) { \
        printf("FAILED\n"); \
        printf("Function %s returned %d, expected %d at %s:%d\n", \
            #func, result, expected, __FILE__, __LINE__); \
        test_failed = 1; \
        return; \
    } \
} while (0)

#define ASSERT_FUNC_FAILS(func, ...) do { \
    int result = func(__VA_ARGS__); \
    if (result >= 0) { \
        printf("FAILED\n"); \
        printf("Function %s should have failed but returned %d at %s:%d\n", \
            #func, result, __FILE__, __LINE__); \
        test_failed = 1; \
        return; \
    } \
} while (0)

#endif // TEST_FRAMEWORK_H
