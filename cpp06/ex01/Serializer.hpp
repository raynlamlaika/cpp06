
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

typedef struct Data
{
    int i;
    char *k;
} Data;

class Serializer
{
private:

public:
    Serializer();
    Serializer &operator=(Serializer const &other);
    Serializer(Serializer const &other);
    ~Serializer();

    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);


};

#endif