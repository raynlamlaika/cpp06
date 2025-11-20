
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>

typedef struct Data
{
    void * var;
} Data;

class Serializer
{
private:

public:
    Serializer();
    Serializer operator=(Serializer const &other);
    Serializer(Serializer const &other);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);


};

#endif