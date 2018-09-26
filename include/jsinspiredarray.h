#ifndef JS_INSPIRED_ARRAY_H
#define JS_INSPIRED_ARRAY_H

#include <iostream>

template <typename T>
struct Node {
  T info;
  Node<T>* next;
  Node<T>* prev;
  Node(T info): info(info), next(nullptr), prev(nullptr){}
  ~Node(){}
};

template <typename T>
class LinkedListIterator{
  // TODO
};

template <typename T>
class JSInspiredArray {
  // TODO
};

#endif
