add_library(heapsort heapsort.cpp heap.cpp heap.h)
target_link_libraries(heapsort PUBLIC cxx_setup)