#include "Serializer.hpp"

#include  <iostream>

int main()
{

    Data *P = new Data;
    Serializer obj;

    P->i = 'R';

    uintptr_t raw1 = obj.serialize(P);

    std::cout << "this is the varible data: " << P->i << std::endl;
    std::cout << "this is the varible raw: " << raw1  << std::endl;

    Data *raw2 = obj.deserialize(raw1);

    std::cout << "this is the varible raw1: " << raw1 << std::endl;
    std::cout << "this is the varible raw2: " << raw2->i  << std::endl;


    delete P;
    return 0; 
}

