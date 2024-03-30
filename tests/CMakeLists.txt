add_executable(
        heap_test
        heap_test.cpp
)
target_link_libraries(
        heap_test
        GTest::gtest_main
        GTest::gmock_main
        heapsort
)

add_executable(
        heapsort_test
        heapsort_test.cpp
)
target_link_libraries(
        heapsort_test
        GTest::gtest_main
        GTest::gmock_main
        heapsort
)

add_executable(
        complex_class_test
        complex_class_test.cpp
)
target_link_libraries(
        complex_class_test
        GTest::gtest_main
        GTest::gmock_main
        utils
)

include(GoogleTest)
gtest_discover_tests(heap_test)
gtest_discover_tests(heapsort_test)