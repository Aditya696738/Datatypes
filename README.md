# Datatypes

A brief, example-driven introduction to fundamental C++ datatypes, intended for beginners and learners.


## Primitive types (typical sizes on 64-bit Linux/macOS — implementation defined)
- bool — 1 byte
- char / signed char / unsigned char — 1 byte
- short (short int) — usually 2 bytes
- int — usually 4 bytes
- long (long int) — usually 8 bytes
- long long (long long int) — usually 8 bytes
- float — 4 bytes
- double — 8 bytes
- long double — platform dependent (often 16 bytes)


## Derived datatypes

Derived datatypes are built from primitives and include:
- Arrays — contiguous sequences of elements.
  - C-style: int a[3];
  - std::array and std::vector are safer, dynamic alternatives.
- Pointers — hold addresses of objects; allow dynamic allocation and indirection.
  - int *p = &x;
- References — aliases for existing objects; must be initialized and cannot be reseated.
  - int &r = x;
- Functions and function pointers — functions are types; pointers/reference-to-function let you pass callbacks.
  - using Func = int(*)(int,int);
- cv-qualified types (const / volatile) and pointer-to-member types.


Example:
```c++
int arr[3] = {1,2,3};
int *p = arr;       
int &r = arr[0];   
```

## User-defined datatypes
- User-defined types let you model domain concepts:

 - struct vs class
    struct: members default to public.
    class: members default to private.
 - enum / enum class
    enum class Color { Red, Green }; // scoped, strongly typed
 - union — overlapping storage for different members (use with care).

 - typedef / using — create aliases.

 - Templates — parametric polymorphism for types and functions.

Example :
```c++
struct Point {
    double x{};
    double y{};
};

class Person {
private:
    std::string name;
    int age;
public:
    Person(std::string n, int a) : name(std::move(n)), age(a) {}
    std::string get_name() const { return name; }
    int get_age() const { return age; }
};

```


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

```c++
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
