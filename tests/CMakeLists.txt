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
gtest_discover_tests(heap_test)