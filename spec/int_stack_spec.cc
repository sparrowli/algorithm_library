#include "src/int_stack.h"

#include "gtest/gtest.h"

namespace {

class IntStackSpec : public testing::Test {
 protected:
  
  virtual void SetUp() {
  	s2_ = new IntStack(3);
  }

  virtual void TearDown() {
    if (s2_ != nullptr) {
      delete s2_;
    }
  }

  IntStack s1_;
  IntStack *s2_;
};

TEST_F(IntStackSpec, DefaultConstructor) {
  EXPECT_TRUE(s1_.IsEmpty());
  EXPECT_EQ(kDefaultMaxElements, s1_.max_elements());
  EXPECT_FALSE(s1_.IsFull());
}

TEST_F(IntStackSpec, ConstructorWithMaxElements) {
  EXPECT_TRUE(s2_->IsEmpty());
  EXPECT_EQ(3, s2_->max_elements());
  EXPECT_FALSE(s2_->IsFull());
}

TEST_F(IntStackSpec, PushElements) {
  EXPECT_TRUE(s2_->IsEmpty());

  s2_->Push(1);
  EXPECT_EQ(1, s2_->Peek());
  s2_->Push(2);
  EXPECT_EQ(2, s2_->Peek());
  s2_->Push(3);
  EXPECT_EQ(3, s2_->Peek());

  EXPECT_EQ(IntStack::kStackIsTooFullToPush, s2_->Push(1));

  EXPECT_TRUE(s2_->IsFull());

  EXPECT_EQ(3, s2_->Pop());
  EXPECT_EQ(2, s2_->Pop());
  EXPECT_EQ(1, s2_->Pop());
  
  EXPECT_EQ(IntStack::kStackIsEmptyNotToPeek, s2_->Peek());
  EXPECT_EQ(IntStack::kStackIsEmptyNotToPop, s2_->Pop());

}

}  // namespace