# Datatypes

A brief, example-driven introduction to fundamental C++ datatypes, intended for beginners and learners.

## Contents
- Overview
- What’s in this repository
- Primitive types and typical sizes
- Signed vs unsigned
- Floating point types
- Characters and strings
- Literals, constants, and suffixes
- Type conversion and casting
- Modern C++ helpers (auto, nullptr, enum class)
- Example and how to build
- Contributing
- License

## Overview
This repository provides a compact explanation of built-in C++ datatypes, common pitfalls, and small example code you can compile to inspect sizes, limits, and basic conversions on your platform.

## What’s in this repository
- Short explanations and notes about common C++ datatypes
- Small example demonstrating sizeof, numeric limits, casting, and auto/type deduction (examples/types_demo.cpp)

## Primitive types (typical sizes on 64-bit Linux/macOS — implementation defined)
- bool — 1 byte
- char / signed char / unsigned char — 1 byte
- short (short int) — usually 2 bytes
- int — usually 4 bytes
- long (long int) — usually 8 bytes on LP64, 4 bytes on LLP64 (Windows)
- long long (long long int) — usually 8 bytes
- float — 4 bytes
- double — 8 bytes
- long double — platform dependent (often 16 bytes)

Use sizeof(T) to verify sizes on your target platform.

## Signed vs Unsigned
- Signed types represent negative and positive values.
- Unsigned types represent non-negative values and extend the positive range.
- Avoid mixing signed and unsigned in comparisons or arithmetic to prevent surprising implicit conversions.

## Floating point
- float (single precision), double (double precision), long double (extended precision).
- Beware precision loss and rounding; use std::numeric_limits to inspect precision and ranges.

## Characters and strings
- char stores a character or small integer value.
- Use std::string for text. Consider char16_t/char32_t or encoding libraries for Unicode/UTF handling.

## Literals and constants
- Integer: 42, 0xff (hex), 0b1010 (binary, C++14+), 042 (octal)
- Floating: 3.14, 2.5e-3
- Suffixes: u / U (unsigned), l / L (long), ll / LL (long long), f / F (float)
- Use const or constexpr for compile-time constants

## Type conversion and casting
- Implicit conversions occur automatically; be cautious of narrowing and overflow.
- Prefer explicit casts when needed:
  - static_cast<T>(expr)
  - reinterpret_cast for low-level pointer conversions (use sparingly)
  - const_cast to add/remove constness (use carefully)
- Avoid C-style casts in new C++ code.

## Modern C++ helpers
- auto for type deduction
- nullptr for null pointers
- using / typedef for aliases
- enum class for strongly typed, scoped enumerations

## Example: print sizes and numeric limits
Save the following as examples/types_demo.cpp and compile it:

```cpp
#include <iostream>
#include <limits>
#include <cstdint>
#include <string>

int main() {
    std::cout << "Sizes (bytes) on this platform:\n";
    std::cout << "bool: " << sizeof(bool) << "\n";
    std::cout << "char: " << sizeof(char) << "\n";
    std::cout << "short: " << sizeof(short) << "\n";
    std::cout << "int: " << sizeof(int) << "\n";
    std::cout << "long: " << sizeof(long) << "\n";
    std::cout << "long long: " << sizeof(long long) << "\n";
    std::cout << "float: " << sizeof(float) << "\n";
    std::cout << "double: " << sizeof(double) << "\n";
    std::cout << "long double: " << sizeof(long double) << "\n\n";

    std::cout << "int min: " << std::numeric_limits<int>::min()
              << ", int max: " << std::numeric_limits<int>::max() << "\n";

    double x = 3.14159;
    int xi = static_cast<int>(x);
    std::cout << "x=" << x << " -> xi=" << xi << "\n";

    auto s = std::string("hello");
    std::cout << "string s: " << s << "\n";

    return 0;
}
```

## Build & run
Using g++:

```
g++ -std=c++17 -O2 -Wall examples/types_demo.cpp -o types_demo
./types_demo
```

Using clang++:

```
clang++ -std=c++17 -O2 -Wall examples/types_demo.cpp -o types_demo
./types_demo
```

## Contributing
Contributions and improvements are welcome. Suggested additions:
- More examples (pointers, references, arrays, structs)
- Platform-specific notes (Windows vs Linux/macOS differences)
- Examples showing undefined/implementation-defined behavior

