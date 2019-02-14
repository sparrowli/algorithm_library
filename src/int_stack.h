#ifndef ALGORITHM_LIBRARY_SRC_INT_STACK_H_
#define ALGORITHM_LIBRARY_SRC_INT_STACK_H_

#define kDefaultMaxElements 10

class IntStack {
 public:
  IntStack();
  explicit IntStack(int max_elements);

  ~IntStack();
  int max_elements() const;

  bool IsEmpty() const;
  bool IsFull() const;

  int Push(int element);
  int Pop();
  int Peek();

  enum Error {
    kNoError = 0,
    kStackIsTooFullToPush = -1,
    kStackIsEmptyNotToPop = -2,
    kStackIsEmptyNotToPeek = -3,
  };

 private:
  int top_;
  int max_elements_;
  int *elements_;
};

#endif  // ALGORITHM_LIBRARY_SRC_INT_STACK_H_