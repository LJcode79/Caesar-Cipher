#ifndef CHAR_STACK_H
#define CHAR_STACK_H
#include <string>
using namespace  std;

struct Node {
  char letter;
  Node* prev;
  Node* next;
};
class CharStack {
  private:
    Node* top_;
    Node* bottom_;
  public:
    CharStack();  //create an empty stack
    ~CharStack(); //release all nodes

    bool isEmpty() const; //return true for an empty stack
    char& top() const;    //return the reference to the top character
    void push(char);      //push a character to the top of the stack
    void pop();           //pop the top character from the stack

    //return the characters in the stack from bottom to top
    string toString() const; 
};

#endif
