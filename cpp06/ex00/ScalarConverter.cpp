
#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    static_cast<void>(other);
    return(*this);
}

ScalarConverter::~ScalarConverter()
{
}

std::string split(std::string str, char delimiter)
{
    std::string reslt;
    size_t start = 0;

    size_t end = str.find(delimiter);
    reslt = str.substr(start, end - start);
    return reslt;
}

int CharConv(t_helper helper, char * string)
{
    long double  holder = 0;
    if (!helper.fdouble && !helper.fflag)
        holder = std::strtold(string, NULL);
        // holder = static_cast<int>(std::strtold(string, NULL));
    else
    {
        if (helper.fflag)
        {
            string[strlen(string) - 1] = '\0';
            holder = static_cast<int>(std::strtold(string, NULL));
        }
        else if (helper.fdouble)
        {
            std::string helper(string);
            helper = split(helper, '.');
            holder = static_cast<int>(std::strtold(helper.c_str(), NULL));
        }
    }
    long double value = std::strtold(string, NULL);

    if (INFINITY < value)
        return(std::cout << "float : inf\n", 1);
    if (value > 127 || value < -128)
    {
        std::cout << "char: impossible" << std::endl;
        return 1;
    }
    if (value >= 32 && value <= 126)
    {
        
        std::cout << "char: '";
        std::cout << static_cast<char>(holder);
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        return 1;
    }
    std::cout << "'"<< std::endl;
    return (1);
}


int IntConv(t_helper helper, char *string)
{
    
    
    long double value = std::strtold(string, NULL);
    if (value > INT_MAX || value < INT_MIN)
    {
        std::cout << "int: impossible" << std::endl;
        return 15;
    }
    int holder;
    if (!helper.fdouble && !helper.fflag)
        holder = static_cast<int>(std::strtold(string, NULL));
    else
    {
        if (helper.fflag)
        {
            string[helper.index_fflag] = '\0';
            holder = static_cast<int>(std::strtold(string, NULL));
        }
        if (helper.fdouble)
        {
            std::string helper(string);
            helper = split(helper, '.');
            holder = static_cast<int>(std::strtold(helper.c_str(), NULL));;
        }
    }

    std::cout << "int: " << holder << std::endl;
    return (1);
}


char* precision_helper(const char* str)
{
    size_t precision = 7;
    size_t len = std::strlen(str);
    char* result = new char[len + 1];
    std::strcpy(result, str);

    char* dot = std::strchr(result, '.');
    if (dot && std::strlen(dot) > precision)
        dot[1 + precision] = '\0';

    return result; // caller must delete[] result
}

int FloatConv(t_helper helper, char * string)
{
    (void)helper;

    long double value =std::strtof(string, NULL);
    // check the overflow and the underflow

    if (INFINITY < value)
        return(std::cout << "float : inf\n", 1);
    if (value > MAXFLOAT || value < -MAXFLOAT)
    {
       std::cout << "float : impossible\n";
        return 0;
    }

    std::cout << "float: " << std::fixed << std::setprecision(8) << value ;
    std::cout << "f" << std::endl;
    return (1);
}


int DoubleConv(t_helper helper, char * string)
{
    (void)helper;
    double value;
    std::stringstream ss(string);
    ss >> value;
    if (ss.fail())
        return (std::cout << "double: impossible\n" , 0 );
    value = std::strtod(string, NULL);

    std::cout << "double: " << std::fixed << std::setprecision(8) << value << std::endl;
    return (1);
}

#include "stdio.h"

t_helper typeTaker(char *copy)
{
    t_helper taker;
    int len;
    int index = 0;
    taker.index_sing    = 0;
    taker.fflag         = 0;
    taker.index_fflag   = 0;
    taker.fdouble       = 0;
    taker.index_fdouble = 0;
    len                 = static_cast<int>(strlen(copy));


    if (!std::strcmp(copy, "nan")   || !std::strcmp(copy, "nanf")  ||
    !std::strcmp(copy, "+inf")  || !std::strcmp(copy, "+inff") ||
    !std::strcmp(copy, "-inf")  || !std::strcmp(copy, "-inff"))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (copy[std::strlen(copy) - 1] == 'f')
            std::cout << "float: " << copy << std::endl;
        else
            std::cout << "float: " << copy << "f" << std::endl;

        if (copy[std::strlen(copy) - 1] == 'f' && strcmp(copy, "+inf") && strcmp(copy, "-inf"))
            std::cout << "double: " 
                    << std::string(copy, std::strlen(copy) - 1)
                    << std::endl;
        else
            std::cout << "double: " << copy << std::endl;

        exit(1);
        return taker;
    }


    while (copy[index]) 
    {
        if ((copy[index] < 127 && copy[index] > -127) && len == 1 && !isdigit(copy[index]))
        {
            return taker;
        }
        else if (isdigit(copy[index]))
            index++;
        else if (copy[index] == '-' || copy[index] == '+')
        {
            if (index != 0)
            {
                std::cout << "syntax error exit error(152)" << std::endl;
                exit(14);
            }
            index++;
            if (!isdigit(copy[index]) && copy[index] != '.')
            {
                std::cout << "syntax error exit error(2225)" << std::endl;
                exit(14);
            }
        }
        else if (copy[index] == 'f')
        {
            taker.fflag += 1;
            taker.index_fflag = index;
            index++;
        }
        else if(copy[index] == '.')
        {
            taker.index_fdouble = index;
            taker.fdouble += 1;
            index++;
            if (!isdigit(copy[index]))
            {
                std::cout << "syntax error exit error(14)" << std::endl;
                exit(14);
            }
        }
        else
        {
            std::cout << "syntax error exit error(15)" << std::endl;
            exit(15);
        }
    }

    if (taker.fflag)
    {
        if (taker.fdouble == 0)
        {
            std::cout << "syntax error exit error ." << std::endl;
            exit(15);
        }
        if (taker.index_fflag != len - 1 || taker.fflag > 1)
        {
            std::cout << "syntax error exit error" << std::endl;
            exit(15);
        }
    }

    if (taker.fdouble)
    {
        if(taker.fdouble && taker.sing == 1)
        {
            std::cout << "syntax error exit error" << std::endl;
            exit(15);
        }
        if (taker.index_fdouble == len - 1 || taker.fdouble > 1)
        {
            std::cout << "syntax error exit error" << std::endl;
            exit(15);
        }
    }
    return (taker);
}

int  ScalarConverter::convert(const char* str)
{
    if (!str)
        std::cout << "you can't pass in empty string" << std::endl;

    if (isprint(str[0]) && strlen(str) == 1 && !isdigit(str[0]))
    {
        int hrlper = static_cast<int>(str[0]);
        std::ostringstream oss;
        oss << hrlper;
        std::string s = oss.str();
        str = s.c_str();
    }
    char* copy = const_cast<char *>(str);

    t_helper parced = typeTaker(copy);
    
    // first convert to char 
    CharConv(parced, copy);
    // sec convert to int 
    // int value = 
    IntConv(parced, copy);
    // if (value == 0 || value == 15)
    // {
    //     if (IntConv(parced, copy) == 15)
    //     {
    //         std::cout << "int: impossible\n";
    //         // return 1;
    //     }
    //     else
    //         std::cout << "int coverter error can't take this action" << std::endl;
    // }


    // more convert to float 
    char *precision  = precision_helper(copy);
    FloatConv(parced, precision);
    DoubleConv(parced, precision);

    delete precision;
    return 0;
}
