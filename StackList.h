#include <iostream>
#include "Stack.h"
#include "StackUnderflow.hpp"

template<typename Type>

struct TNode {
  Type data_;
  TNode<Type> *next_;

  TNode(Type newData, TNode<Type> *nextNode) {
    data_ = newData;
    next_ = nextNode;
  }
};

template<typename Type>
class StackList : public A_Stack<Type> {
public:
  StackList();

  ~StackList() override;

  void push(const Type &element) override;

  Type pop() override;

  Type top() override;

  bool isEmpty() override;

  unsigned int getSize();

private:
  unsigned int sizeOfStack_;
  TNode<Type> *currentTop_;
};

template<typename Type>
StackList<Type>::StackList() {
  sizeOfStack_ = 0;
  currentTop_ = nullptr;
}


template<typename Type>
StackList<Type>::~StackList() {
  TNode<Type> *current = currentTop_;
  while (current) {
    TNode<Type> *del = current;
    current = current->next_;
    delete del;
  }
}

template<typename Type>
void StackList<Type>::push(const Type &element) {
  TNode<Type> *node = new TNode<Type>(element, currentTop_);
  sizeOfStack_++;
  currentTop_ = node;
}

template<typename Type>
Type StackList<Type>::top() {
  return currentTop_->data_;
}

template<typename Type>
bool StackList<Type>::isEmpty() {
  return this->getSize() > 0 ? true : false;
}

template<typename Type>
unsigned int StackList<Type>::getSize() {
  return sizeOfStack_;
}

template<typename Type>
Type StackList<Type>::pop() {
  if (getSize() > 0) {
    Type item = currentTop_->data_;
    TNode<Type> *x = currentTop_;
    currentTop_ = currentTop_->next_;
    delete x;
    std::cout << "Printable elements:\t";
    return item;
  } else {
    throw StackUnderflow();
  }
}

