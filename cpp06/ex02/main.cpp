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

    Base *A = generate();
    Base *A1 = generate();
    Base *A2 = generate();
    Base *A3 = generate();
    Base *A4 = generate();
    Base *A5 = generate();
    Base *A6 = generate();

    identify(A);
    identify(A1);
    identify(A2);
    identify(A3);
    identify(A4);
    identify(A5);
    identify(A6);

    identify(*A);
    identify(*A1);
    identify(*A2);
    identify(*A3);
    identify(*A4);
    identify(*A5);
    identify(*A6);
    
    delete A;
    delete A1;
    delete A2;
    delete A3;
    delete A4;
    delete A5;
    delete A6;

    return 1;
}

