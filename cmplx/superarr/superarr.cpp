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
    SuperArray<T>::SuperArray(std::initializer_list<T> init_list) {
        n = init_list.size();
        arr = new T[n];
        T *ptr = arr;
        for (auto it = init_list.begin(); it != init_list.end(); it++) {
            *ptr = *it;
            ptr++;
        }
    }
        template <typename T>

    SuperArray<T>::SuperArray(int size, T elem) {
                n = size;
                arr = new T[n];
                for (int i = 0; i < n; i++) {
                    arr[i] = elem;
                }
                
            }
    template <typename T>

    int SuperArray<T>::size() {
        return n;
    }
    template <typename T>

    T& SuperArray<T>::operator[](int ind) {
        if (ind >= n) {
            std::cout << "Out of bounds access." << std::endl;
            exit(0);
        }
        return arr[ind];
    } 
    template <typename T>

    SuperArray<T>::~SuperArray() {
        delete[] arr;
    }
        
}

// int main() {
//     cmplx::superarr::SuperArray arr(10, 10);
//     std::cout << arr << std::endl;
// }