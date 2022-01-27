/* 
 * Name: Lawrence John Balanza
 * Course: CS 211
 * Date: 11/28/2021
 * Mini Project 5: Caesar Cipher
 * Description:  Work with two classes to support the encrypting and decrypting of a message
*/
#include <iostream>
#include <fstream>
#include <string>
#include "CaesarCipher.h"
#include "CharStack.h"
using namespace std;

int main() {
  string s;
  char c;
  CharStack undo, redo;

  char str[256];
    cout<< "Enter the name of an existing text file(type message.txt to begin): ";
  cin.get(str,256);

  ifstream is(str);
  while(is.get(c)){
    if (c == '<'){
      if (undo.isEmpty() == false){
        char temp = undo.top();
        undo.pop();
        redo.push(temp);
      }
    }
    else if(c == '>'){
      if(redo.isEmpty() == false){
        char temp = redo.top();
        redo.pop();
        undo.push(temp);
      }
    }
    else{
      undo.push(c);
      while (redo.isEmpty() == false){
        redo.pop();
      }
    }
  }
  is.close();
  //add statements to process message.txt file using the undo and redo stacks according to the directions provided in the project description. You goal is to keep only the message to be encrypted in the undo stack when all characters in message.txt have been processed.

  //The following code has been set up to help you test the CaesarCipher class. Do not change them.
  string message = undo.toString(); //to retrieve the message to be processed
  string key, encrypted_message;
  cout << "Message left in the undo stack:\n" << message << endl;
  char option;
  do {
    cout << "What is your key (digits only)? ";
    cin >> key;
    cin.ignore();

    CaesarCipher multiple_bits(key);
    encrypted_message = multiple_bits.cipher(message);
    cout << encrypted_message << endl;
    cout << "Decrypted back to:" << endl;
    cout << multiple_bits.decipher(encrypted_message) << endl;

    cout << "Try another key? (y/n) ";
    cin >> option; 
  } while (option == 'y' || option == 'Y');

  return 0;
}
