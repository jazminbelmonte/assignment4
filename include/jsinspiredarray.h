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

public:
  // TODO: LinkedListOperator(Node<T>*)
  LinkedListIterator(Node<T>* ptr): current(ptr){}

  // TODO: Operator++
  LinkedListIterator<T>& operator++(){
    current = current->link;
    return *this;
  }

  // TODO: Operator*
  T operator*(){
    return current->info;
  }

  // TODO: Operator==
  bool operator==(const LinkedListIterator<T>& rhs) {
    return current == rhs.current;
  }

  // TODO: Operator!=
  bool operator!=(const LinkedListIterator<T>& rhs) {
    return current != rhs.current;
  }

private:
  // TODO: current
  Node<T>* current;

};

template <typename T>
class JSInspiredArray {

public:
  // TODO: JSInspiredArray()
  JSInspiredArray(): count(0), first(nullptr), last(nullptr){}

  // TODO: JSInspiredArray(const JSInspiredArray<T>&)
  JSInspiredArray(const JSInspiredArray<T>& array): JSInspiredArray(){
    auto current = array.first;
    while (current){
      add(current->info);
      current = current->link;
    }
  }

  // TODO: operator=(const JSInspiredArray<T>&)

  // TODO: push(T)

  // TODO: pop(T)

  // TODO: unshift(T)

  // TODO: shift()

  // TODO: concat(const JSInspiredArray<T>&)

  // TODO: find(T)

  // TODO: friend ostream <<

  // TODO: empty()

  // TODO: length()

  // TODO: begin()

  // TODO: end()

  // TODO: ~JSInspiredArray()

protected:
    Node<T>* first;
    Node<T> last;
    unsigned count;
};

#endif
