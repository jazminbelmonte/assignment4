#ifndef JS_INSPIRED_ARRAY_H
#define JS_INSPIRED_ARRAY_H

#include <iostream>
#include <stdexcept>

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
  // LinkedListOperator(Node<T>*)
  LinkedListIterator(Node<T>* ptr): current(ptr){}

  // Increment Operator++ 
  LinkedListIterator<T>& operator++(){
    current = current->next;
    return *this;
  }

  // Operator*
  T operator*(){
    return current->info;
  }

  // Operator==
  bool operator==(const LinkedListIterator<T>& rhs) {
    return current == rhs.current;
  }
  
  // Operator!=
  bool operator!=(const LinkedListIterator<T>& rhs) {
    return current != rhs.current;
  }

private:
  // current
  Node<T>* current;

};

template <typename T>
class JSInspiredArray {

public:
  // JSInspiredArray()
  JSInspiredArray(): count(0), first(nullptr), last(nullptr){}

  //The copy constructor; creates an object that is an
  //exact replica of its array argument.
  JSInspiredArray(const JSInspiredArray<T>& array): JSInspiredArray(){

    Node<T>* current = array.first;

	while (current){
		push(current->info)
		current = current->next;
	}
  }
	
  //The copy assignment operator, makes the array on
  //the left-hand side of the assignment an exact replica
  //of the array on the right-hand side.
  JSInspiredArray<T>& operator=(const JSInspiredArray<T>& array){
      
    destroy();
    
    Node<T>* current = array.first;

	while (current){
		push(current->info)
		current = current->next;
	}
  }

  //push(T)	
  //adds nodes to the end        
  unsigned push(T insertItem){

    Node<T>* newNode = new Node<T>(insertItem);

    if (first == nullptr){ //if list is empty
    	first = newNode;
	last = newNode;
        count++;
    } 
    else { //add node to the end
      newNode->next = nullptr;
      newNode->prev = last;
      last->next = newNode;
      last = newNode;
      count++;
    }
    return count;
  }

  // pop()
  //Removes the last node and returns its info.
  T pop(){
      
    if (first == nullptr){//if list is empty
      throw std::runtime_error("List is empty, nothing to remove");
    } 
    T info = last->info;
    if (first == last){ 
      	first = nullptr;
      	last = nullptr;
      	count--;
    } 
    else { 
    	last->prev->next = nullptr;
	last = last->prev;
	count--;
    }
    return info;
  }

  // unshift(T)
  //Adds a node at the beginning of the array; returns
  //the new size of the array.
  unsigned unshift(T insertItem){

    Node<T>* newNode = new Node<T>(insertItem);

    if(first == nullptr){ //if the list is empty
      first = newNode;
      last = newNode;
      count++;
    } 
    else {
      newNode->next = first;
      newNode->prev = nullptr;
      first->prev = newNode;
      first = newNode;
      count++;
    }
    return count;
  }

  // shift()
  //Removes the first node and returns its info.
  T shift(){

    if (first = nullptr){
      throw std::runtime_error("List is empty, nothing to remove");
    } 
    T info = first->info;
    if (first == last){
      first == nullptr;
      last == nullptr;
      count--;
    } 
    else {
      first->next->prev = nullptr;
      first = first->next;
      count--;
    }
    return info;
  }


  // concat(const JSInspiredArray<T>&)
  //Adds (concatenates) the nodes of its array argument
  //one at a time to the end of the array.
  void concat(const JSInspiredArray<T>& array){
     Node<T>* current = array.first;
     int counter = 0;
     while(counter < array.count)
     {
	 push(current->info);
	 current = current->next;
	 counter++;
     }
  }

  // find(T)
  //searches through the array to find specific value
  LinkedListIterator<T> find(T findItem){
    bool found = false;
    Node<T>* current = first;

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
    } else if (!found) {
      return false;    
    }
  }

  // friend ostream <<
  friend std::ostream& operator<<(std::ostream& out, const JSInspiredArray& array) {
    Node<T>* current = array.first;
    while (current){
      out << current->info << " ";
      current = current->next;
    }
    return out;
  }

  // empty()
  // checks if list in empty
  bool const empty(){
    return (first == nullptr);
  }

  // length()
  // returns length of list
  unsigned const length(){
    return count;
  }

  // begin()
  //Returns an iterator pointing at the first node of the array.
  LinkedListIterator<T> begin(){
    return LinkedListIterator<T>(first);
  }

  // end()
  //Returns an iterator pointing at what is past the last node
  //of the array, which is ?nullptr?.
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

    //destroy function used to deallocate existing memory	
    void destroy(){
      Node<T>* current = first;
        
      while(current){
        Node<T>* temp = current;
        current = current->next;
        delete temp;
        temp = nullptr;
      }
        
      first = nullptr;
      last = nullptr;
      count = 0;
    }
};

#endif
