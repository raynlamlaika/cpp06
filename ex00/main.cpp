
#include "ScalarConverter.hpp"







int main(int ac, char **av)
{
    (void)ac;
    ScalarConverter *ps = new ScalarConverter;
    std::cout << "this is the main function "<<  std::endl;
    ps->convert(av[1]);
    return 0;
}