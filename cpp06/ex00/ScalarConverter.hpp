

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <cerrno>
#include <cfloat>

#include "climits"
#include "cstring"
#include "iostream"

typedef struct s_helper {
  int sing;
  int index_sing;
  int fflag;
  int index_fflag;
  int fdouble;
  int index_fdouble;
} t_helper;

class ScalarConverter {
 private:
 public:
  // orthodox Form
  ScalarConverter();
  //  copy constructor
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();
  static void detecter(t_helper parced, std::string copyString);

  // definition of static method is : first the this pointer can't point to it
  // it can be  called without creating the class object
  static int convert(char *str);  // string litterale
};

#endif
