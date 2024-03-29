//===-- cmplx/linkedlist/linkedlist.h - Linked List Definition --------------===//
///
/// \file
/// This file contains the declaration of the Linked List data structure.
///
//===-----------------------------------------------------------------===//

#pragma once
#include <iosfwd>
#include <initializer_list>

namespace cmplx::linkedlist {

    template <typename T>
    class ListNode {
        public:
            T val;
            ListNode* next;
            ListNode(T);
            ListNode(T, ListNode*);
    };

    template <typename T>
    class LinkedList {
        ListNode<T>* head;
        ListNode<T>* tail;
        
        public:
            LinkedList(std::initializer_list<T>);
            LinkedList();
            void insert(T);
            ~LinkedList();
            friend std::ostream & operator << (std::ostream &out, LinkedList<T> &c)
                {
                    ListNode<T>* tmp = c.head;
                    while (tmp) {
                        out << tmp -> val << " ";
                        tmp = tmp -> next;
                    }
                    return out;
            }
    };
}
