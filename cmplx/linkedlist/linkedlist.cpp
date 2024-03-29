//===-- cmplx/linkedlist/linkedlist.cpp - Linked List Implementation -----------===//
///
/// \file
/// This file contains the implementation of the Linked List data structure.
///
//===--------------------------------------------------------------------===//

#include "linkedlist.h"
#include <iostream>
namespace cmplx::linkedlist {
    template <typename T>
    ListNode<T>::ListNode(T val) {
        this -> val = val;
        this -> next = NULL;
    }

    template <typename T>
    ListNode<T>::ListNode(T val, ListNode* next) {
        this -> val = val;
        this -> next = next;
    }

    template <typename T>
    LinkedList<T>::LinkedList() {
        head = NULL;
        tail = NULL;
    }

    template <typename T>
    void LinkedList<T>::insert(T val) {
        if (!head) {
            head = new ListNode<T>(val);
            tail = head;
        }
        else {
            tail -> next = new ListNode<T>(val);
            tail = tail -> next;
        }
    }

    template <typename T>
    LinkedList<T>::~LinkedList() {
        ListNode<T>* tmp;
        while (!head) {
            tmp = head;
            head = head -> next;
            delete tmp;
        }
    }

    template <typename T>
    LinkedList<T>::LinkedList(std::initializer_list<T> init_list) : LinkedList<T>::LinkedList() {

        for (auto &c: init_list) {
            insert(c);
        }
    }
}

// int main() {
//     cmplx::linkedlist::LinkedList<int> list {10, 20, 30, 40};
//     std::cout << list << std::endl;
// }