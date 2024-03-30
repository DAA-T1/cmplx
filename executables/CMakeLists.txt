
add_executable(print_hello print_hello.cpp)
add_executable(subham_tests subham_sample.cpp)
target_link_libraries(print_hello PRIVATE heapsort cxx_setup)
 target_link_libraries(subham_tests PRIVATE readfile superarr cxx_setup)