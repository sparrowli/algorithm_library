#include "src/linked_list.h"

#include "gtest/gtest.h"

namespace {

class LinkedListSpec : public testing::Test {
 protected:
  virtual void SetUp() {

  }

  virtual void TearDown() {

  }

  LinkedList single_list_;
};

TEST_F(LinkedListSpec, DefaultListNodeConstructor) {
  ListNode *one = new ListNode();

  EXPECT_EQ(-1, one->data);
  EXPECT_EQ(nullptr, one->next);
}

TEST_F(LinkedListSpec, ThreeNodeLinkedList) {
  ListNode *head = nullptr;
  ListNode *one = new ListNode();
  ListNode *two = new ListNode();
  ListNode *three = new ListNode();

  one->data = 1;
  one->next = two;

  head = one;

  two->data = 2;
  two->next = three;

  three->data = 3;
  three->next = nullptr;

  EXPECT_EQ(1, one->data);
  EXPECT_EQ(two, one->next);

  EXPECT_EQ(2, two->data);
  EXPECT_EQ(three, two->next);

  EXPECT_EQ(3, three->data);
  EXPECT_EQ(nullptr, three->next);
}


}  // namespace