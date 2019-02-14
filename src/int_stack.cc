#include "src/int_stack.h"

#define RETURN_ON_ERR(expr)  \
  do {                       \
    int error = (expr);      \
    if (error != kNoError) { \
      return error;          \
    }                        \
  } while (0)                \



IntStack::IntStack() : top_(-1),
  elements_(new int[kDefaultMaxElements]),
  max_elements_(kDefaultMaxElements) {}

IntStack::IntStack(int max_elements) {
  top_ = -1;
  elements_ = new int[max_elements];
  max_elements_ = max_elements;
}

IntStack::~IntStack() {
  top_ = -1;
  if (elements_ != nullptr) {
    delete [] elements_;
    elements_ = nullptr;
  }
}

int IntStack::max_elements() const {
  return max_elements_;
}

bool IntStack::IsEmpty() const {
  return top_ == -1;
}

bool IntStack::IsFull() const {
  return top_ + 1 == max_elements_;
}

int IntStack::Push(int element) {
  if (IsFull()) {
    return kStackIsTooFullToPush;
  } else {
    elements_[++top_] = element;
  }

  return kNoError;
}

int IntStack::Pop() {
  if (IsEmpty()) {
    return kStackIsEmptyNotToPop;
  } else {
    return elements_[top_--];
  }
}

int IntStack::Peek() {
  if (IsEmpty()) {
    return kStackIsEmptyNotToPeek;
  } else {
    return elements_[top_];
  }
}