#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <climits>


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
  ScalarConverter();
  ScalarConverter(ScalarConverter const &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

  public:
    static int convert(char *str);
};

#endif
