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
        return (new A());
    else if (RandomValue < 70)
        return (new B());
    else// RandomValue < 100
        return (new C());
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "the type of pointer is from the class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "the type of pointer is from the class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "the type of pointer is from the class C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        Base &ptr = dynamic_cast<A&>(p);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Base &ptr =dynamic_cast<B&>(p);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Base &ptr = dynamic_cast<C&>(p);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}



int main()
{
    
    return 1;
}
