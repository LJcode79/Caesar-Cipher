//implement the member functions of the CaesarCipher class.
#include <string>
#include <iostream>
#include <string.h> 
#include "CaesarCipher.h"
using namespace std;

const string CaesarCipher::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

CaesarCipher::CaesarCipher(const string& key){
  this->key_ = new int[key.size()];
  this->size_ = key.size();
  for (int i = 0; i < key.size(); i++){
    char a = key.at(i);
    this->key_[i] = a - '0';
  }
}

CaesarCipher::~CaesarCipher(){
  cout << "Releasing from CaesarCipher queue." << endl;
  delete [] this->key_;
}

string CaesarCipher::cipher(const string& s){
  string str = "";
  for (int i = 0; i < s.size(); i++){
    if (ALPHABET.find(s.at(i)) != string::npos){
      int found = ALPHABET.find(s.at(i));
      found = (found + this->key_[i%this->size_])%26;
      str = str + ALPHABET.at(found);
    }
    else{
      str = str + s.at(i);
    }
  }
  return str;
}

string CaesarCipher::decipher(const string& s){
  string str = "";
  for (int i = 0; i < s.size(); i++){

    if (ALPHABET.find(s.at(i)) != string::npos){
      int found = ALPHABET.find(s.at(i));
      found = (found - this->key_[i%this->size_]);
      if (found < 0){
        found = 26 + found;
      }
      str = str + ALPHABET.at(found);
    }
    else{
      str = str + s.at(i);
    }
  }
  return str;
}