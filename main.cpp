#include "cripto.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
    byte key;
    string str, path;
    int i;
    Cripto * cripto = new Cripto();

    cin >> key;
    cin >> path;
    //cin >> i;

    cripto -> setKey(key);
    cripto -> setPath(path);

    if(argv[0] == "./cipher")
    cripto -> cipher(cripto -> getPath(), cripto -> getKey());
    if(argv[0] == "./decipher")
    cripto -> decipher(cripto -> getPath(), key);
    
    //while((in.tellg() =! in.end))
       // out.put(op((byte) c, key));
    
    delete cripto;
    return 0;
}
