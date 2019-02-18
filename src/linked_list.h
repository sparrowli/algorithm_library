#ifndef ALGORITHM_LIBRARY_SRC_LINKED_LIST_H_
#define ALGORITHM_LIBRARY_SRC_LINKED_LIST_H_

typedef struct ListNode {
  int data;
  ListNode *next;

  ListNode() : data(-1), next(nullptr) {}
  ListNode(int v) : data(v), next(nullptr) {}
} ListNode;

class LinkedList {

};

#endif  // ALGORITHM_LIBRARY_SRC_LINKED_LIST_H_