#include "Serializer.hpp"

#include  <iostream>

int main()
{

    Data *P = new Data;
    P->i = 'R';

    

    std::cout << "this is the varible data: " << P->i << std::endl;
    std::cout << "this is the varible raw: " <<  &P->i  << std::endl;
    
    
    uintptr_t raw1 = Serializer::serialize(P);
    Data *raw2 = Serializer::deserialize(raw1);

    std::cout << "this is the varible raw1: " << &raw2->i << std::endl;
    std::cout << "this is the varible raw2: " << raw2->i  << std::endl;


    delete P;
    return 0; 
}

