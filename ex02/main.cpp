#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base* generate(void)
{
    std::srand(time(NULL));
    const int RandomValue = std::rand() % 100;
    if (RandomValue < 35)
    {
        // creat A
        return (new A()); // hmmm what is the type of cast nedd here
    }
    else if (RandomValue < 70)
    {
        // creat B
        return (new B());
    }
    else if (RandomValue < 100)
    {
        // creat C
        return (new C());
    }
}
void identify(Base* p)
{

}

void identify(Base& p)
{

}



int main()
{
    
    return 1;
}