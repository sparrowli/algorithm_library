#ifndef ALGORITHM_LIBRARY_SRC_INT_QUEUE_H_
#define ALGORITHM_LIBRARY_SRC_INT_QUEUE_H_

#define kDefaultMaxSize 3

class IntQueue {
 public:
  IntQueue() : head_(-1), last_(-1), max_size_(kDefaultMaxSize),
               elements_(new int[kDefaultMaxSize]) {}

  ~IntQueue() {
    if (elements_ != nullptr) {
      delete [] elements_;
      elements_ = nullptr;
    }
  }

  enum Error {
    kNoError = 0,
    kQueueIsTooFullToEnqueue = -1,
    kQueueIsEmptyNotToDequeue = -2,
  };

  bool IsEmpty() const {
    return (head_ == -1);
  }

  bool IsFull() const {
    bool is_full = (head_ == 0 && last_ == max_size_ - 1)
                 || (last_ + 1 == head_);

    return is_full;
  }

  int Enqueue(int element) {
    if (IsFull()) {
      return kQueueIsTooFullToEnqueue;
    } 

    if (IsEmpty()) {
      ++head_;
    }
    last_ = ++last_ % max_size_;
    elements_[last_] = element;

    return kNoError;
  }

  int Dequeue() {
    if (IsEmpty()) {
      return kQueueIsEmptyNotToDequeue;
    }
    int element = elements_[head_];

    if(head_ == last_) {
      head_ = -1;
      last_ = -1;
    } else {
      head_ = (head_ + 1) % max_size_;
    }

    return element;
  }

 private:
  int head_;
  int last_;

  int max_size_;

  int *elements_;
};

#endif  // ALGORITHM_LIBRARY_SRC_INT_QUEUE_H_