# cmplx-journey

A journey with complex numbers.

## The question

> *Implement Heapsort and Quicksort on complex numbers, where < is defined as the L2 norm. Compare them according to
their asymptotic time-space, complexity and real-time complexity. Then compare the y-component and, finally, the
x-component.*

## Style Conventions

- Always `snake_case` for everything, except class names, for which we want `TitleCase`. Use descriptive names. They can
  be long. Use english to make it make sense.
    - An example of using English well: use `is_alive_and_well` for booleans, etc.
- Use `clangformat` to format the styles, please use `{ }` for every code block. Use `LLVM` Coding standards.
    - [LLVM Coding Standards](https://llvm.org/docs/CodingStandards.html)
    - `clang-format -style=llvm` do this.
- Add a header comment.
- Use `.hpp` files.

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

## Testing

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
