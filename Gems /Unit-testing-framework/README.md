# C Unit Testing Framework

A lightweight unit testing framework for C programs.

## Features

- Simple test case definition with `TEST(name)`
- Basic assertions with `ASSERT(condition)`
- Value comparison with `ASSERT_EQUAL(expected, actual)`
- Function testing with `ASSERT_FUNC(expected, func, ...)`
- Error case testing with `ASSERT_FUNC_FAILS(func, ...)`
- Line number and file reporting for failed tests

## Installation

1. Copy `test_framework.h` to your project directory
2. Include the header in your test files: `#include "test_framework.h"`

## Usage

```c
#include "test_framework.h"

// Define your test
TEST(addition) {
    ASSERT_EQUAL(4, 2 + 2);
}

// Run test
int main() {
    RUN_TEST(addition);
    return 0;
}
```

## API Reference

### Macros

- `TEST(name)`: Define a test case
- `RUN_TEST(name)`: Execute a test case
- `ASSERT(condition)`: Check if condition is true
- `ASSERT_EQUAL(expected, actual)`: Compare two values
- `ASSERT_FUNC(expected, func, ...)`: Test function return value
- `ASSERT_FUNC_FAILS(func, ...)`: Test function failure case

## License

MIT License
