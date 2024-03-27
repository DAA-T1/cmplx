# cmplx

A journey with complex numbers: DAA Assignment on Heapsort and Quicksort.

## The Question.

> *Implement Heapsort and Quicksort on complex numbers, where < is defined as the L2 norm. Compare them according to
their asymptotic time-space, complexity and real-time complexity. Then compare the y-component and, finally, the
x-component.*

## Style Conventions.

This project follows the [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html). Please
use `clang-format -style=llvm` do this.

- In general, names should be in camel case (e.g. TextFileReader and isLValue()). Different kinds of declarations have
  different rules:
    - Type names (including classes, structs, enums, typedefs, etc.) should be nouns and start with an upper-case
      letter (
      e.g. TextFileReader).
    - Variable names should be nouns (as they represent state). The name should be camel case, and start with an upper
      case
      letter (e.g. Leader or Boats).
    - Function names should be verb phrases (as they represent actions), and command-like function should be imperative.
      The
      name should be camel case, and start with a lower case letter (e.g. openFile() or isFoo()).
- Add a header comment describing each source file.
- Use `.h` files.
- Files should follow snake_case naming, eg: `foo_bar.cpp`.

## Build System.

This project uses [CMake](https://cmake.org/) as its build system! Please ensure that you have CMake install on your
local machine.

### Building the project

Run the following commands from the project's root directory.

```cmd
cmake -S . -B build
```

```cmd
cmake --build build
```

### Running executables

After building the project natively, executables such as `print_hello` can be run through
the following command from the project root directory.

```cmd
./build/executables/print_hello
```

## Testing.

This project uses [GoogleTest](https://google.github.io/googletest/) for unit tests. Please write unit tests for all
library related code.

All test are stored in the `tests` directory. Follow the examples present in the `tests` directory
especially `tests/CMakeLists.txt` to understand
how tests are added.

### Running tests

Please run the following command from the project's build directory to run all tests
after building the project of course.

```cmd
ctest --output-on-failure
```
