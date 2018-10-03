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
      current = current->next;
    }
  }

  // TODO: operator=(const JSInspiredArray<T>&)
  JSInspiredArray<T>& operator=(const JSInspiredArray<T>& array){

  }

  // TODO: push(T)
  unsigned push(T){

  }

  // TODO: pop(T)
  T pop(T){

  }

  // TODO: unshift(T)
  unsigned unshift(T){

  }

  // TODO: shift()
  T shift(){

  }

  // TODO: concat(const JSInspiredArray<T>&)
  void concat(const JSInspiredArray<T>& array){

  }

  // TODO: find(T)
  LinkedListIterator<T> find(T){

  }

  // TODO: friend ostream <<
  friend std::ostream& operator<<(std::ostream& out, const JSInspiredArray& array) {
    auto current = array.first;
    while (current){
      out << current->info << ", ";
      current = current->next;
    }

    return out;
  }

  // TODO: empty()
  bool const empty(){
    return (first == nullptr);
  }

  // TODO: length()
  unsigned const length(){
    return count;
  }

  // TODO: begin()
  LinkedListIterator<T> begin(){

  }

  // TODO: end()
  LinkedListIterator<T> end(){

  }

  // TODO: ~JSInspiredArray()
  ~JSInspiredArray(){
    auto current = first;
    while(current){
      auto temp = current;
      current = current->next;
      delete temp;
    }
    first = nullptr;
    last = nullptr;
    count = 0;
  }

protected:
    Node<T>* first;
    Node<T>* last;
    unsigned count;
};

#endif
