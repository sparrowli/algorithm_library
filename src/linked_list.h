#ifndef ALGORITHM_LIBRARY_SRC_LINKED_LIST_H_
#define ALGORITHM_LIBRARY_SRC_LINKED_LIST_H_

typedef struct ListNode {
  int data;
  ListNode *next;

  ListNode() : data(0), next(nullptr) {}
} ListNode;

class LinkedList {

};

#endif  // ALGORITHM_LIBRARY_SRC_LINKED_LIST_H_