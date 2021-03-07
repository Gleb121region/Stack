//
// Created by Gleb on 04.03.2021.
//

#ifndef HOMETASK_STACK_H
#define HOMETASK_STACK_H


template<class Type>
class A_Stack {
public:
  virtual ~A_Stack() = default;
  virtual void push(const Type &element) = 0;
  virtual Type pop() = 0;
  virtual Type top() = 0;
  virtual bool isEmpty() = 0;
};


#endif //HOMETASK_STACK_H
