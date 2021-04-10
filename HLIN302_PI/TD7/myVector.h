#include <iostream>

template <typename T>
class MyVector{

 private:
  T *data;
  int n;
  int alloc;

  void extend();

 public:
  MyVector();
  MyVector(int n);
  MyVector(const MyVector tab&);

  MyVector& operator=(const MyVector tab&);

  size_t size() const;
  T& at(int i);

  int find(const T e&) const;
  void erase(size_t);

  void push_back(T e);

  ~MyVector();

};
#include "myVector.tcc"
