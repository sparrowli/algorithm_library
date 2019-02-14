#include "src/int_queue.h"

#include "gtest/gtest.h"

namespace {

class IntQueueSpec : public testing::Test {
 protected:
  virtual void SetUp() {

  }

  virtual void TearDown() {

  }

  IntQueue q1_;
};

TEST_F(IntQueueSpec, DefaultConstructor) {
  
  EXPECT_TRUE(q1_.IsEmpty());
  q1_.Enqueue(1);
  EXPECT_EQ(1, q1_.Dequeue());
  EXPECT_EQ(IntQueue::kQueueIsEmptyNotToDequeue, q1_.Dequeue());
}

TEST_F(IntQueueSpec, IsQueueFull) {
  
  EXPECT_TRUE(q1_.IsEmpty());
  q1_.Enqueue(1);
  q1_.Enqueue(2);
  q1_.Enqueue(3);
  
  EXPECT_TRUE(q1_.IsFull());
}

}  // namespace