
#include "ScalarConverter.hpp"







int main(int ac, char **av)
{
    (void)ac;
    ScalarConverter *ps = new ScalarConverter;
    ps->convert(av[1]);
    return 0;
}