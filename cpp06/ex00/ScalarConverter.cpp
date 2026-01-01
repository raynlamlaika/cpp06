
#include "ScalarConverter.hpp"
#include "cstring"
#include "iostream"
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>


ScalarConverter::ScalarConverter()
{
    std::cout <<  "constractor is called\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    static_cast<void>(other);
    return(*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout <<  "deconstractor is called\n";
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
    int holder = 0;
    if (!helper.fdouble && !helper.fflag)
        holder = static_cast<int>(std::strtold(string, NULL));
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
    // check overflow right here in the int part
    long overflowcheck = static_cast<long>(std::strtold(string, NULL));
    if ((static_cast<int>(overflowcheck) > 127) && (static_cast<int>(overflowcheck) < -128))
    {
        std::cout << "char: impossible" << std::endl;
        return 1;
    }
    // check overflow right here in the doule part


    if (isprint(holder))
    {
        std::cout << "char: '";
        std::cout << (char)holder; //check
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
    //check over flow right here of the holder

    
    long double value = std::strtold(string, NULL);

    if (value > INT_MAX || value < INT_MIN)
    {
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

#include <iomanip>

int FloatConv(t_helper helper, char * string)
{
    (void)helper;

    long double value =std::strtof(string, NULL);
    // check the overflow and the underflow

    if (INFINITY < value)
        return(std::cout << "float : inf\n", 1);
    if (value > MAXFLOAT || value < -MAXFLOAT)
        return 0;

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
        return (std::cout << "double: over/under flow detected\n" , 0 );
    // ss >> string;
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


    if (strcmp(copy,"nanf") == 0 || strcmp(copy,"inff") == 0 || \
    strcmp(copy,"+inff") == 0 || strcmp(copy,"-inff") == 0 ||strcmp(copy,"-inf") == 0 \
    || strcmp(copy,"+inf") == 0 || \
    strcmp(copy,"nan") == 0)
    {
        return (taker);
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
                std::cerr << "syntax error exit error(152)" << std::endl;
                exit(14);
            }
            index++;
            if (!isdigit(copy[index]) && copy[index] != '.')
            {
                std::cerr << "syntax error exit error(2225)" << std::endl;
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
                std::cerr << "syntax error exit error(14)" << std::endl;
                exit(14);
            }
        }
        else
        {
            std::cerr << "syntax error exit error(15)" << std::endl;
            exit(15);
        }
    }
    // the f position 
    
    if (taker.fflag)
    {
        if (taker.fdouble == 0)
        {
            std::cerr << "syntax error exit error ." << std::endl;
            exit(15);
        }
        if (taker.index_fflag != len - 1 || taker.fflag > 1)
        {
            std::cerr << "syntax error exit error(2225)" << std::endl;
            exit(15);
        }
    }
    // the point position 
    if (taker.fdouble)
    {
        if(taker.fdouble && taker.sing == 1)
        {
            std::cerr << "syntax error exit error(2225)" << std::endl;
            exit(15);
        }
        // taker.index_fdouble == 0 || 
        if (taker.index_fdouble == len - 1 || taker.fdouble > 1)
        {
            std::cerr << "syntax error exit error(2225)" << std::endl;
            exit(15);
        }
    }
    return (taker);
}

int  ScalarConverter::convert(const char* str)
{
    if (!str)
        std::cerr << "you can't pass in empty string" << std::endl;

    if (isprint(str[0]) && strlen(str) == 1 && !isdigit(str[0]))
    {
        int hrlper = static_cast<int>(str[0]);
        std::ostringstream oss;
        oss << hrlper;
        std::string s = oss.str();
        str = s.c_str();
    }
    char* copy = strdup(str);
    
    // need to hard code the inf nan ...

    // get the type of input 
    t_helper parced = typeTaker(copy);
    
    // first convert to char 
    if (CharConv(parced, copy) == 0)
    {
        std::cerr << "char coverter error can't take this action" << std::endl;
    }
    // sec convert to int
    int value = IntConv(parced, copy);
    if (value == 0 || value == 15)
    {
        if (IntConv(parced, copy) == 15)
        {
            std::cerr << "int: overflow/underflow is catched\n";
            // return 1;
        }
        else
            std::cerr << "int coverter error can't take this action" << std::endl;
    }


    // more convert to float 
    if (FloatConv(parced, precision_helper(copy)) == 0)
    {
        // std::cerr << "float coverter error can't take this action" << std::endl;
    }
    // last convert to double 
    if (DoubleConv(parced, precision_helper(copy)) == 0)
    {
        // std::cerr << "double :coverter error can't take this action" << std::endl;
    }
    return 0;
}
