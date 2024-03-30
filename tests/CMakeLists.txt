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
        quicksort_test
        quicksort_test.cpp
)
target_link_libraries(
        quicksort_test
        GTest::gtest_main
        GTest::gmock_main
        quicksort
)

include(GoogleTest)

gtest_discover_tests(quicksort_test)
gtest_discover_tests(heap_test)
gtest_discover_tests(heapsort_test)