

#include "ScalarConverter.hpp"
#include "cstring"
#include "iostream"
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>




ScalarConverter::ScalarConverter()
{

}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return(*this);
}
ScalarConverter::~ScalarConverter()
{

}















typedef struct  s_helper
{
    int sing         ;
    int index_sing   ;
    int fflag        ;
    int index_fflag  ;
    int fdouble      ;
    int index_fdouble;
}               t_helper;

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
    int holder;
    if (!helper.fdouble && !helper.fflag)
        holder = (char)atoi(string);
    else
    {
        if (helper.fflag)
        {
            string[strlen(string) - 1] = '\0';
            holder = atoi(string);
        }
        else if (helper.fdouble)
        {
            std::string helper(string);
            helper = split(helper, '.');
            holder = atoi(helper.c_str());
        }
    }
    // check overflow right here in the int part
    long overflowcheck = atol(string);
    if (overflowcheck > 255 || overflowcheck < -255)
    {
        std::cout << "char: Non displayable" << std::endl;
        return 1;
    }
    // check overflow right here in the doule part

    std::cout << "char: '";
    if (isprint(holder))
        std::cout << (char)holder; //check
    else
    {
        std::cout << "char: Non displayable" << std::endl;
        return 1;
    }
    std::cout << "'"<< std::endl;
    return (1);
}


int IntConv(t_helper helper, char * string)
{
    int holder;
    if (!helper.fdouble && !helper.fflag)
        long holder = atol(string);

    else
    {
        if (helper.fflag)
        {
            string[strlen(string) - 1] = '\0';
            holder = atoi(string);
        }
        if (helper.fdouble)
        {
            std::string helper(string);
            helper = split(helper, '.');
            holder = atoi(helper.c_str());
        }
    }
    std::cout << "int: " << holder << std::endl;
    return (1);
}

int FloatConv(t_helper helper, char * string)
{
    (void)helper;
    float holder;
    holder = std::strtof(string, NULL);
    std::cout << "float: " << holder ;
    std::cout << "f";
    std::cout << std::endl;
    // if (!helper.fdouble && !helper.fflag)
    // {
    //     holder = atof(string);
    //     std::cout << "float: " << holder ;
    //     std::cout << ".0f";
    //     std::cout << std::endl;
    //     return 1;
    // }
    // else
    // {
    //     if (helper.fflag)
    //     {
    //         holder = atof(string);
    //         std::cout << "float: " << holder ;
    //         // std::cout << ".0f";
    //         std::cout << std::endl;
    //         return 1;
    //     }
    //     else if (helper.fdouble)
    //     {
    //         std::string helper(string);
    //         helper = split(helper, '.');
    //         holder = atoi(helper.c_str());
    //     }
    // }
    return (1);

}

int DoubleConv(t_helper helper, char * string)
{
    (void)helper;
    long double holder;
    holder  = std::strtold(string, NULL);
    std::cout << "double: " << holder ;
    // std::cout << ".0";
    std::cout << std::endl;
    // if (!helper.fdouble && !helper.fflag)
    // {
    //     holder = atoi(string);
    //     std::cout << "double: " << holder ;
    //     std::cout << ".0";
    //     std::cout << std::endl;
    //     return 1;
    // }

    return (1);
}

t_helper typeTaker(char *copy)
{
    t_helper taker;
    int len;
    int index;
    
    index               = 0;
    taker.sing          = 0;
    taker.index_sing    = 0;
    taker.fflag         = 0;
    taker.index_fflag   = 0;
    taker.fdouble       = 0;
    taker.index_fdouble = 0;
    len                 = strlen(copy);

    if (copy[index] == '-' || copy[index] == '+' )
    {
        // negative values is passed
        taker.index_sing = index;
        taker.sing = 1;
        index++;
    }

    while (copy[index])
    {
        if (isdigit(copy[index]))
            index++;
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
        if (taker.index_fflag != len - 1 || taker.fflag > 1)
        {
            std::cout <<"   "<<taker.index_fflag << "  " << len << "  " << index << " "<<  taker.fflag <<" 'f' position isn't incorrrect" << std::endl;
            exit(15);
        }
    }
    // the point position 
    if (taker.fdouble)
    {
        if(taker.fdouble && taker.sing == 1)
        {
            std::cout <<"   "<<taker.index_fflag << "  " << len << "  " << index << " "<<  taker.fflag <<"  '.' - position isn't incorrrect" << std::endl;
            exit(15);
        }
        if (taker.index_fdouble == 0 ||taker.index_fdouble == len - 1 || taker.fdouble > 1)
        {
            std::cout <<"   "<<taker.index_fflag << "  " << len << "  " << index << " "<<  taker.fflag <<"  '.' position isn't incorrrect" << std::endl;
            exit(15);
        }
    }
    std::cout << "string is valid ----->: " << copy << std::endl;
    return (taker);
}


int  convert(const char* str)
{
    if (!str)
        std::cerr << "you can't pss in empty string" << std::endl;

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
    if (IntConv(parced, copy) == 0)
    {
        std::cerr << "int coverter error can't take this action" << std::endl;
    }
    // more convert to float 
    if (FloatConv(parced, copy) == 0)
    {
        std::cerr << "float coverter error can't take this action" << std::endl;
    }
    // last convert to double 
    if (DoubleConv(parced, copy) == 0)
    {
        std::cerr << "double coverter error can't take this action" << std::endl;
    }
    return 0;
}

int main()
{
    // char is good need just to handel the over/under flow
    //  handel the float and doulbe and   the edg cases nan inf
    convert("494444444444444444.444444444444443"); 
    return 0;
}


