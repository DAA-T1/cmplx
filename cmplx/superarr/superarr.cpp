//===-- cmplx/superarr/superarr.cpp - Super Array Implementation -----------===//
///
/// \file
/// This file contains the implementation of th Super Array data structure.
///
//===--------------------------------------------------------------------===//

#include "superarr.h"
#include <iostream>

namespace cmplx::superarr {
    template <typename T>
    class SuperArray {
        int n;
        T* arr;

        public:
            SuperArray(std::initializer_list<T> init_list) {
                n = init_list.size();
                arr = new T[n];
                T *ptr = arr;
                for (auto it = init_list.begin(); it != init_list.end(); it++) {
                    *ptr = *it;
                    ptr++;
                }
            }
            SuperArray(int size, T elem) {
                n = size;
                arr = new T[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = elem;
                }
                
            }

            int size() {
                return n;
            }

            T& operator[](int ind) {
                if (ind >= n) {
                    std::cout << "Out of bounds access." << std::endl;
                    exit(0);
                }
                return arr[ind];
            } 

            ~SuperArray() {
                delete[] arr;
            }
            friend std::ostream & operator << (std::ostream &out, SuperArray<T> &c)
                {
                    for (int i = 0; i < c.size(); i++) {
                        out << c[i] << " ";
                    }
                    return out;
                }
    };
}// namespace cmplx::heapsort

// int main() {
//     cmplx::superarr::SuperArray array = {1,2,3,4,5};
//     std::cout << array << std::endl;
//     std::cout << array << std::endl;
// }
