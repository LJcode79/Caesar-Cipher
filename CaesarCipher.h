#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H
#include <string>
using namespace std;

class CaesarCipher {
  private:
    static const string ALPHABET;
    int* key_;  //to hold the key in an int array
    int size_;  //to note the size of the array
  public:
    CaesarCipher(const string& key);  //to create the key_
    ~CaesarCipher();                  //to release the memory for key_
    string cipher(const string& s);   //to encryt a message
    string decipher(const string& s); //to descrypt a message
};

#endif
