
add_executable(
        hello_test
        hello_test.cpp
)
target_link_libraries(
        hello_test
        GTest::gtest_main
)

add_executable(
        life_test
        life_test.cpp
)
target_link_libraries(
        life_test
        GTest::gtest_main
        heapsort
)

add_executable(
        heap_test
        heap_test.cpp
)
target_link_libraries(
        heap_test
        GTest::gtest_main
        heapsort
)

include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(life_test)