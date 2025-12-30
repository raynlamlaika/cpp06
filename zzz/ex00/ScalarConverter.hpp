

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <cstring>
#include "climits"
#include <cmath>
#include <limits>

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