#include "src/lc_add_two_numbers.h"

#include "src/linked_list.h"

#include "gtest/gtest.h"

class AddTwoNumbersSpec : public testing::Test {
 public:
  virtual void SetUp() {

  }

  virtual void TearDown() {

  }

  void FreeLinkedList(ListNode** head) {
    ListNode* freed_node = nullptr;
    ListNode* list = *head;

    while (list != nullptr) {
      freed_node = list;

      list = list->next;

      delete freed_node;

      freed_node = nullptr;
    }

    *head = nullptr;
  }

 protected:
  AddTwoNumbersSolution s;
};

TEST_F(AddTwoNumbersSpec, AddTwoNumbersCleanCodeWithDifferentLength) {
  ListNode *l1_node1 = new ListNode(0);
  ListNode *l1_node2 = new ListNode(1);

  l1_node1->next = l1_node2;

  ListNode *l2_node1 = new ListNode(0);
  ListNode *l2_node2 = new ListNode(1);
  ListNode *l2_node3 = new ListNode(2);

  l2_node1->next = l2_node2;
  l2_node2->next = l2_node3;

  ListNode *expected_node_1 = new ListNode(0);
  ListNode *expected_node_2 = new ListNode(2);
  ListNode *expected_node_3 = new ListNode(2);

  expected_node_1->next = expected_node_2;
  expected_node_2->next = expected_node_3;


  ListNode *added_two_numbers = s.AddTwoNumbersCleanCode(l1_node1, l2_node1);

  EXPECT_TRUE(added_two_numbers != nullptr);

  ListNode *expect_head = expected_node_1;
  ListNode *actual_head = added_two_numbers;

  while (expect_head != nullptr && actual_head != nullptr) {

    EXPECT_EQ(expect_head->data, actual_head->data);

    expect_head = expect_head->next;
    actual_head = actual_head->next;
  }

  FreeLinkedList(&l1_node1);

  EXPECT_TRUE(l1_node1 == nullptr);

  FreeLinkedList(&l2_node1);
  EXPECT_TRUE(l2_node1 == nullptr);

  FreeLinkedList(&expected_node_1);
  EXPECT_TRUE(expected_node_1 == nullptr);

  FreeLinkedList(&added_two_numbers);
  EXPECT_TRUE(added_two_numbers == nullptr);
}

TEST_F(AddTwoNumbersSpec, AddTwoNumbersCleanCodeWithOneEmpty) {
  ListNode *l1_node1 = nullptr;

  ListNode *l2_node1 = new ListNode(0);
  ListNode *l2_node2 = new ListNode(1);

  l2_node1->next = l2_node2;

  ListNode *expected_node_1 = new ListNode(0);
  ListNode *expected_node_2 = new ListNode(1);

  expected_node_1->next = expected_node_2;


  ListNode *added_two_numbers = s.AddTwoNumbersCleanCode(l1_node1, l2_node1);

  EXPECT_TRUE(added_two_numbers != nullptr);

  ListNode *expect_head = expected_node_1;
  ListNode *actual_head = added_two_numbers;

  while (expect_head != nullptr && actual_head != nullptr) {

    EXPECT_EQ(expect_head->data, actual_head->data);

    expect_head = expect_head->next;
    actual_head = actual_head->next;
  }

  FreeLinkedList(&l1_node1);

  EXPECT_TRUE(l1_node1 == nullptr);

  FreeLinkedList(&l2_node1);
  EXPECT_TRUE(l2_node1 == nullptr);

  FreeLinkedList(&expected_node_1);
  EXPECT_TRUE(expected_node_1 == nullptr);

  FreeLinkedList(&added_two_numbers);
  EXPECT_TRUE(added_two_numbers == nullptr);
}

TEST_F(AddTwoNumbersSpec, AddTwoNumbersCleanCodeWithCarryAtLast) {

  ListNode *l1_node1 = new ListNode(9);
  ListNode *l1_node2 = new ListNode(9);
  l1_node1->next = l1_node2;

  ListNode *l2_node1 = new ListNode(1);

  ListNode *expected_node_1 = new ListNode(0);
  ListNode *expected_node_2 = new ListNode(0);
  ListNode *expected_node_3 = new ListNode(1);

  expected_node_1->next = expected_node_2;
  expected_node_2->next = expected_node_3;

  ListNode *added_two_numbers = s.AddTwoNumbersCleanCode(l1_node1, l2_node1);

  EXPECT_TRUE(added_two_numbers != nullptr);

  ListNode *expect_head = expected_node_1;
  ListNode *actual_head = added_two_numbers;

  while (expect_head != nullptr && actual_head != nullptr) {

    EXPECT_EQ(expect_head->data, actual_head->data);

    expect_head = expect_head->next;
    actual_head = actual_head->next;
  }

  FreeLinkedList(&l1_node1);

  EXPECT_TRUE(l1_node1 == nullptr);

  FreeLinkedList(&l2_node1);
  EXPECT_TRUE(l2_node1 == nullptr);

  FreeLinkedList(&expected_node_1);
  EXPECT_TRUE(expected_node_1 == nullptr);

  FreeLinkedList(&added_two_numbers);
  EXPECT_TRUE(added_two_numbers == nullptr);
}

TEST_F(AddTwoNumbersSpec, AddTwoNumbers) {
  ListNode *first_node_1 = new ListNode(2);
  ListNode *first_node_2 = new ListNode(4);
  ListNode *first_node_3 = new ListNode(3);

  first_node_1->next = first_node_2;
  first_node_2->next = first_node_3;

  ListNode *l1_head = new ListNode();
  l1_head->next = first_node_1;

  ListNode *second_node_1 = new ListNode(5);
  ListNode *second_node_2 = new ListNode(6);
  ListNode *second_node_3 = new ListNode(4);

  second_node_1->next = second_node_2;
  second_node_2->next = second_node_3;

  ListNode *l2_head = new ListNode();
  l2_head->next = second_node_1;

  ListNode *expected_node_1 = new ListNode(7);
  ListNode *expected_node_2 = new ListNode(0);
  ListNode *expected_node_3 = new ListNode(8);

  expected_node_1->next = expected_node_2;
  expected_node_2->next = expected_node_3;

  ListNode *expected_added_head = new ListNode();
  expected_added_head->next = expected_node_1;

  ListNode *added_two_numbers = s.AddTwoNumbers(l1_head, l2_head);

  EXPECT_TRUE(added_two_numbers);

  while (expected_added_head->next != nullptr && added_two_numbers->next != nullptr) {
    expected_added_head = expected_added_head->next;
    added_two_numbers = added_two_numbers->next;

    EXPECT_EQ(expected_added_head->data, added_two_numbers->data);
  }
}