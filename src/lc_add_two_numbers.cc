#include "src/lc_add_two_numbers.h"

#include <iostream>

ListNode* AddTwoNumbersSolution::AddTwoNumbersCleanCode(ListNode *l1, ListNode* l2) {
  ListNode* head_dummy = new ListNode(0);
  ListNode* it = head_dummy;

  ListNode* p = l1;
  ListNode* q = l2;

  int carry = 0;

  while (p != nullptr || q != nullptr) {
    
    int added = (p != nullptr) ? p->data : 0;
    int addee = (q != nullptr) ? q->data : 0;

    int sum = added + addee + carry;
    carry = sum / 10;

    it->next = new ListNode(sum % 10);
    it = it->next;

 
    p = p != nullptr ? p->next : nullptr;
    q = q != nullptr ? q->next : nullptr;
  }

  
  if (carry == 1) {
    it->next = new ListNode(carry);
  }


  return head_dummy->next;
}

ListNode* AddTwoNumbersSolution::AddTwoNumbers(ListNode *l1, ListNode* l2) {
  ListNode* sum = new ListNode();

  ListNode* head1 = l1;
  ListNode* head2 = l2;
  ListNode* sum_head = sum;

  int k = 0; 

  while (head1->next != nullptr || head2->next != nullptr) {


    ListNode* node = new ListNode(0);
    sum_head->next = node;

    if (head1->next != nullptr) {
      head1 = head1->next;

      node->data = (node->data + head1->data + k) % 10 ;

      if (k != 0) k = 0;

      k = (node->data + head2->data) / 10;
    }

    if (head2->next != nullptr) {
      head2 = head2->next;

      node->data = (node->data + head2->data) % 10;
      k = (node->data + head2->data) / 10;
    }

  }

  return sum;
}