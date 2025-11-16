

#include "ScalarConverter.hpp"


int CharConv(char * string)
{


    return (1);
}

int IntConv(char * string)
{


    return (1);
}

int FloatConv(char * string)
{


    return (1);
}

int DoubleConv(char * string)
{


    return (1);
}

void  convert(const char* str)
{
    if (!str)
        std::cerr << "you can't pss in empty string" << std::endl;
    for (int i = 0;str[i]; i++)
    {
        if (str[i] && iscntrl(str[i]))
        {
            std::cerr << "can't pass in Non printable characters" << std::endl;
            return ;
        }
    }

    // char *copy = new char (strlen(str) + 1);
    char* copy = strdup(str);
    // first convert to char 
    if (CharConv(copy) == 0)
    {
        std::cerr << "char coverter error can't take this action" << std::endl;
    }
    // sec convert to int
    if (IntConv(copy) == 0)
    {
        std::cerr << "int coverter error can't take this action" << std::endl;
    }
    // more convert to float 
    if (FloatConv(copy) == 0)
    {
        std::cerr << "float coverter error can't take this action" << std::endl;
    }
    // last convert to double 
    if (DoubleConv(copy) == 0)
    {
        std::cerr << "double coverter error can't take this action" << std::endl;
    }




}




