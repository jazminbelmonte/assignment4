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

//  // TODO: JSInspiredArray(const JSInspiredArray<T>&)
//  //The copy constructor; creates an object that is an
//  //exact replica of its array argument.
//  JSInspiredArray(const JSInspiredArray<T>& array): JSInspiredArray(){
//    auto current = array.first;
//    while (current){
//      add(current->info);
//      current = current->next;
//    }
//  }

//  // TODO: operator=(const JSInspiredArray<T>&)
//  //The copy assignment operator, makes the array on
//  //the left-hand side of the assignment an exact replica
//  //of the array on the right-hand side.
//  JSInspiredArray<T>& operator=(const JSInspiredArray<T>& array){
//    destroy();
//    auto current = array.first;
//    while(current){
//      add(current->info);
//      current = current->next;
//    }
//    return *this;
//  }

  // TODO: push(T)
  unsigned push(T insertItem){
    Node<T>* newNode;

    newNode = new Node<T>;
    newNode->info = insertItem;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (first == nullptr){ //if list is empty, new node will be the only node
      first = newNode;
      last = newNode;
      count++;
    } else { //add node to the end
      last->next = newNode;
      newNode->prev = last;
      newNode->next = nullptr;
      last = newNode;
      count++;
    }
    return count;
  }

  // TODO: pop(T)
  //Removes the last node and returns its info.
  T pop(T){

  }

  // TODO: unshift(T)
  //Adds a node at the beginning of the array; returns
  //the new size of the array.
  unsigned unshift(T){

  }

  // TODO: shift()
  //Removes the first node and returns its info.
  T shift(){

  }

  // TODO: concat(const JSInspiredArray<T>&)
  //Adds (concatenates) the nodes of its array argument
  //one at a time to the end of the array.
  void concat(const JSInspiredArray<T>& array){

  }

  // TODO: find(T)
  LinkedListIterator<T> find(T findItem){
    bool found = false;
    auto current = first;

    while(current != nullptr && !found){
      if(current->info == findItem){
        found = true;
      }
      else {
        current = current->next;
      }
    }
    if (found){
      return LinkedListIterator<T>(current);
    }
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
  //Returns an iterator pointing at the first node of the array.
  LinkedListIterator<T> begin(){
    return LinkedListIterator<T>(first);
  }

  // TODO: end()
  //Returns an iterator pointing at what is past the last node
  //of the array, which is ​nullptr​.
  LinkedListIterator<T> end(){
    return LinkedListIterator<T>(nullptr);
  }

  // TODO: ~JSInspiredArray()
  ~JSInspiredArray(){
    destroy();
  }

protected:
    Node<T>* first;
    Node<T>* last;
    unsigned count;

    void destroy(){
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
};

#endif
