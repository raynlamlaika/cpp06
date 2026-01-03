
#include "ScalarConverter.hpp"



int main(int ac, char **av)
{
    if (ac > 2)
        return (std::cout << "invalid args\n", 0);

    ScalarConverter::convert(av[1]);
    return 0;



}