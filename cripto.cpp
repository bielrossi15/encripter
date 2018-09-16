#include <iostream>
#include <fstream>
#include <cstring>
#include "cripto.hpp"

using namespace std;

Cripto::Cripto(){
    key = 0;
    path = "";

};

Cripto::~Cripto(){

};

void Cripto::setKey(byte key){
    this -> key = key;

}

void Cripto::setCharacters(byte *characters){
    this -> characters = characters;

}

void Cripto::setPath(string path){
    this -> path = path;

}

byte Cripto::getKey(){
    
    return key;
}

string Cripto::getPath(){
    
    return path;
}

byte *Cripto::getCharacters(){

    return characters;
}

void Cripto::cipher(string path, byte key)
{
   // Print current working directory.
   //char cwd[1000];
   //getcwd(cwd, 1000);
   //std::cout << "Current working directory: " << cwd << std::endl;

   ifstream file;
   file.open(path);
   if ( !file )
   {
      cerr << "Error: " << strerror(errno);
      //throw std::runtime_error("Unable to open file for reading from");
   }

   file.seekg(0, file.end);
   long size = file.tellg();
   file.seekg(0);

   byte * characters = new byte[size];
   setCharacters(characters);
   file.read(characters, size);
   long n = file.gcount();

   // Only n characters were read.
   if ( n != size )
   {
      cout << n;
   }

   // Encrypt only the number of characters that were read.
   if ( n != size )
   {
      cout << " ERROR";
   }

   // Encrypt only the number of characters were read.
   for(int i = 0; i < n; i++){
      characters[i] += getKey();
   }

   ofstream outfile("out.txt");
   if ( !outfile )
   {
      // Problem opening the file.
      // Throw an exception and get out of the function.
      throw std::runtime_error("Unable to open file for writing to");
   }

   // Write n characters, not size.
   outfile.write(characters, n);
   
}


void Cripto::decipher(string path, byte key){
   //char cwd[1000];
   //getcwd(cwd, 1000);
   //std::cout << "Current working directory: " << cwd << std::endl;

   ifstream file;
   file.open(path);
   if ( !file )
   {
      cerr << "Error: " << strerror(errno);
      throw std::runtime_error("Unable to open file for reading from");
   }

   file.seekg(0, file.end);
   long size = file.tellg();
   file.seekg(0);

   byte * characters = new byte[size];
   setCharacters(characters);
   file.read(characters, size);
   long n = file.gcount();

   // Only n characters were read.
   if ( n != size )
   {
      cout << n;
   }

   // Encrypt only the number of characters that were read.
   if ( n != size )
   {
      // Print a warning message.
   }

   // Encrypt only the number of characters were read.
   for(int i = 0; i < n; i++){
      characters[i] -= getKey();
   }

   ofstream outfile("decipher.txt");
   if ( !outfile )
   {
      // Problem opening the file.
      // Throw an exception and get out of the function.
      throw std::runtime_error("Unable to open file for writing to");
   }

   // Write n characters, not size.
   outfile.write(characters, n);

}