#ifndef HOMETASK_STACKARRAY_H
#define HOMETASK_STACKARRAY_H

#include <iostream>
#include "Stack.h"
#include "StackOverflow.hpp"
#include "StackUnderflow.hpp"
#include "WrongStackSize.hpp"

template<typename Type>

class StackArray : public A_Stack<Type> {
public:
  StackArray(int maxSize);

  ~StackArray() override;

  void push(const Type &element) override;

  Type pop();

  Type top() override;

  bool isEmpty() override;

  unsigned int getSize();

private:
  int sizeOfStack = 0;
  Type *array = NULL;
protected:
  int elementNow = 0;
};

template<typename Type>
StackArray<Type>::StackArray(int maxSize) {
  if (maxSize > 0) {
    array = new Type[maxSize];
    sizeOfStack = maxSize;
  } else {
    throw WrongStackSize();
  }
}

template<typename Type>
StackArray<Type>::~StackArray() {
  delete[] array;
}

template<typename Type>
void StackArray<Type>::push(const Type &element) {
//  int size = sizeOfStack;
//  if (!(element > size)) {
//    array[elementNow] = element;
//    elementNow++;
//  } else {
//    throw StackOverflow();
//  }


  Type *tmp;

  tmp = array;

  // выделить память на 1 элемент больше, чем было выделено до этого
  array = new Type[sizeOfStack + 1];

  // увеличить количество элементов в стеке на 1
  sizeOfStack++;

  // скопировать данные из памяти, на которую указывает tmp в память,
  // на которую указывает stack
  for (int i = 0; i < sizeOfStack - 1; i++)
    array[i] = tmp[i];

  // добавить последний элемент
  array[sizeOfStack - 1] = element;

  // освободить память, выделенную перед этим для stack,
  // на эту память указывает tmp
  if (sizeOfStack > 1)
    delete[] tmp;

  std::cout << "Items have been added to the stack :\t" << element << '\n';
}

template<typename Type>
Type StackArray<Type>::pop() {
  if (sizeOfStack != 0) {
    sizeOfStack--;
    return array[sizeOfStack];
  } else {
    return 0;
  }
}

template<typename Type>
Type StackArray<Type>::top() {
  return array[sizeOfStack - 1];
}

template<typename Type>
bool StackArray<Type>::isEmpty() {
  return getSize() > 0 ? true : false;
}

template<typename Type>
unsigned int StackArray<Type>::getSize() {
  return sizeOfStack;
}

#endif //HOMETASK_STACKARRAY_H
