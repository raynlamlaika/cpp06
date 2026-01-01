#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>


Base* generate(void)
{
    static bool helper = 0 ;
    if (!helper)
    {
        std::srand(time(NULL));
        helper = true;
    } 
    const int RandomValue = std::rand() % 3;
    if (RandomValue == 1)
        return (new A());
    else if (RandomValue == 0)
        return (new B());
    else
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
        std::cout << "the type of pointer passed is type of class A" << std::endl;
        (void)ptr;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ptr =dynamic_cast<B&>(p);
        std::cout << "the type of pointer passed is type of class B" << std::endl;
        (void)ptr;
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
    }
    try
    {
        Base &ptr = dynamic_cast<C&>(p);
        std::cout << "the type of pointer passed is type of class C" << std::endl;
        (void)ptr;
    }
    catch(const std::exception& e)
    {
    }

}




int main()
{
    
    return 1;
}

