//implement the member functions of the CharStack class.
#include <iostream>
#include <string>
#include <sstream>
#include "CharStack.h"
using namespace std;

CharStack::CharStack(){
  this->top_ = this->bottom_ = nullptr;
}

CharStack::~CharStack(){
  Node *ptr = this->top_; 
  cout << "Releasing all letter nodes for a stack." << endl;
  while(ptr != nullptr){
    ptr = ptr->next;
    delete this->top_;
    this->top_ = ptr;
  }
  cout << " done." << endl;
}

bool CharStack::isEmpty() const{
  if (this->top_ == nullptr){
    return true;
  }
  return false;
}

char& CharStack::top() const{
  return this->top_->letter;
}

void CharStack::push(char c){
  Node* ptr = this->top_;
  if ((this->top_ == nullptr) && (this->bottom_ == nullptr)){//Dealing with no element
    this->top_ = this->bottom_ = new Node{c,nullptr,nullptr};
  }
  else{//Dealing with at least one element
    ptr->prev = new Node{c,nullptr,ptr};
    this->top_ = ptr->prev;
    ptr = this->top_;
  }
}

void CharStack::pop(){
  Node* ptr = this->top_;
  if((this->top_ == nullptr) && (this->bottom_ == nullptr)){//Dealing with no element
    cout << "Error, no characters to pop." << endl;
  }
  else if(this->top_ == this->bottom_){//Dealing with only one element
    delete this->top_;
    this->top_ = this->bottom_ = nullptr;
  }
  else {//Dealing with 2 or more elements
    this->top_ = ptr->next;
    delete ptr;
    ptr = this->top_;
    ptr->prev = nullptr;
  }
}

string CharStack::toString() const{
  string s = "";
  if (this->top_ == nullptr){//Dealing with no element
    return "List is empty.";
  }
  else{ //Dealing with more than one element
    Node* ptr = this->bottom_;
    while(ptr!=nullptr){
      s = s+ptr->letter;
      ptr = ptr->prev;
    }
    return s;
  }
}