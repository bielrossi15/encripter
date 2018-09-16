#ifndef CRIPTO_HPP
#define CRIPTO_HPP 
#include<iostream>

using namespace std;
typedef char byte;

class Cripto {
    private:
        byte key;
        string path;
        byte * characters;

    public:
        Cripto();
        ~Cripto();
        byte getKey();
        void setKey(byte key);
        string getPath();
        void setPath(string path);
        byte * getCharacters();
        void setCharacters(byte * characters);
        void cipher(string path, byte key);
        void decipher(string path, byte key);

        
};

#endif 