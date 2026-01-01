

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <cstring>
#include "climits"
#include <cmath>
#include <sstream>
#include <limits>
#include <cstdlib>


typedef struct  s_helper
{
    int sing         ;
    int index_sing   ;
    int fflag        ;
    int index_fflag  ;
    int fdouble      ;
    int index_fdouble;
}               t_helper;


class ScalarConverter
{
    
private:
    
public:
    // orthodox Form
    ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    // definition of static method is : first the this pointer can't point to it 
    // it can be  called without creating the class object
    static int convert(const char* str); // string litterale

};

#endif
