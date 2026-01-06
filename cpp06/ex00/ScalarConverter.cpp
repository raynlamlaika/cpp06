
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  static_cast<void>(other);
  return (*this);
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
  static_cast<void>(other);
}

ScalarConverter::~ScalarConverter() {}

t_helper typeTaker(const char *copy) {
  t_helper taker;
  int len;
  int index = 0;
  taker.index_sing = 0;
  taker.fflag = 0;
  taker.index_fflag = 0;
  taker.fdouble = 0;
  taker.index_fdouble = 0;
  len = static_cast<int>(strlen(copy));

  if (!std::strcmp(copy, "nan") || !std::strcmp(copy, "nanf") ||
      !std::strcmp(copy, "+inf") || !std::strcmp(copy, "+inff") ||
      !std::strcmp(copy, "-inf") || !std::strcmp(copy, "-inff")) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (copy[std::strlen(copy) - 1] == 'f')
      std::cout << "float: " << copy << std::endl;
    else
      std::cout << "float: " << copy << "f" << std::endl;

    if (copy[std::strlen(copy) - 1] == 'f' && strcmp(copy, "+inf") &&
        strcmp(copy, "-inf"))
      std::cout << "double: " << std::string(copy, std::strlen(copy) - 1)
                << std::endl;
    else
      std::cout << "double: " << copy << std::endl;

    exit(1);
    return taker;
  }

  while (copy[index]) {
    if ((copy[index] < 127 && copy[index] > -127) && len == 1 &&
        !isdigit(copy[index])) {
      return taker;
    } else if (isdigit(copy[index]))
      index++;
    else if (copy[index] == '-' || copy[index] == '+') {
      if (index != 0) {
        std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
        exit(14);
      }
      index++;
      if (!isdigit(copy[index]) && copy[index] != '.') {
        std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
        exit(14);
      }
    } else if (copy[index] == 'f') {
      taker.fflag += 1;
      taker.index_fflag = index;
      index++;
    } else if (copy[index] == '.') {
      taker.index_fdouble = index;
      taker.fdouble += 1;
      index++;
      if (!isdigit(copy[index])) {
        std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
        exit(14);
      }
    } else {
      std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
      exit(15);
    }
  }

  if (taker.fflag) {
    if (taker.fdouble == 0) {
      std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
      exit(15);
    }
    if (taker.index_fflag != len - 1 || taker.fflag > 1) {
      std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
      exit(15);
    }
  }

  if (taker.fdouble) {
    if (taker.fdouble && taker.sing == 1) {
      std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
      exit(15);
    }
    if (taker.index_fdouble == len - 1 || taker.fdouble > 1) {
      std::cout << "char : impossible\nint : impossible\nfloat : impossible\ndouble : impossible" << std::endl;
      exit(15);
    }
  }
  return (taker);
}

bool charDetection(t_helper parced, std::string copyString) {
  if (parced.fdouble == 1 || parced.fflag == 1)
    return false;
  
  if (copyString.length() == 1 && !std::isdigit(copyString[0])) {
    int helper = static_cast<int>(copyString[0]);
    
    if (std::isprint(copyString[0]))
      std::cout << "char: '" << copyString[0] << "'" << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
    
    std::cout << "int: " << helper << std::endl;
    float floatHelper = static_cast<float>(copyString[0]);
    std::cout << "float: " << floatHelper << ".0f" << std::endl;
    double doubleHelper = static_cast<double>(copyString[0]);
    std::cout << "double: " << doubleHelper << ".0" << std::endl;
    return true;
  }
  return false;
}


bool intDetection(t_helper parced, std::string copyString)
{

  if (parced.fdouble == 1 || parced.fflag == 1) return false;

  long intval = std::strtol(copyString.c_str(), NULL, 10);
  if (intval < INT_MIN || intval > INT_MAX)
    return false;
  else
    intval = atoi(copyString.c_str());

    
  if (intval < 0 || intval > 127)
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(static_cast<char>(intval)))
    std::cout << "char: '" << static_cast<char>(intval) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  if (intval < INT_MIN || intval > INT_MAX)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(intval) << std::endl;

  float floatHelper = static_cast<float>(intval);
  std::cout << "float: " << std::fixed << std::setprecision(0) << floatHelper;
  if (floatHelper - static_cast<int>(floatHelper) == 0)
    std::cout << ".0f"  << std::endl;
  else
    std::cout << "f" << std::endl;
  double doubleHelper = static_cast<double>(intval);
std::cout << "double: " << std::fixed << std::setprecision(0) << doubleHelper;
  if (doubleHelper - static_cast<int>(doubleHelper) == 0)
    std::cout << ".0" << std::endl;
  else
    std::cout << std::endl;
  return true;
}


bool floatDetection(t_helper parced, std::string copyString)
{
  if (parced.fflag != 1)
    return false;

  float floatval = static_cast<float>(std::strtod(copyString.c_str(), NULL));

  if (floatval < 0 || floatval > 127)
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(static_cast<char>(floatval)))
    std::cout << "char: '" << static_cast<char>(floatval) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  if (floatval < -2147483648.0f || floatval > 2147483647.0f)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(floatval) << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << floatval << "f" << std::endl;
  double doubleHelper = static_cast<double>(floatval);
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << doubleHelper << std::endl;
  return true;
}

bool doubleDetection(t_helper parced, std::string copyString)
{
  (void)parced;

  double doubleval = std::strtod(copyString.c_str(), NULL);

  if (doubleval < 0 || doubleval > 127)
    std::cout << "char: impossible" << std::endl;
  else if (std::isprint(static_cast<char>(doubleval)))
    std::cout << "char: '" << static_cast<char>(doubleval) << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  if (doubleval < INT_MIN || doubleval > INT_MAX)
    std::cout << "int: impossible" << std::endl;
  else
    std::cout << "int: " << static_cast<int>(doubleval) << std::endl;
  float floatHelper = static_cast<float>(doubleval);
  std::cout << "float: " << std::fixed << std::setprecision(1)
            << floatHelper << "f" << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1)
            << doubleval << std::endl;
  return true;
}

void detecter(t_helper parced, std::string copyString) {
  // check for char
  if (charDetection(parced, copyString) == true) {

    return;
  }
  // //check for int
  if (intDetection(parced, copyString) == true) {

    return;
  }

  // //check for float
  if (floatDetection(parced, copyString))
  {
      return ;
  }

  // //check for double
  if (doubleDetection(parced, copyString))
  {
      return ;
  }
}

int ScalarConverter::convert(char *str) {
  if (!str) std::cout << "you can't pass in empty string" << std::endl;



  std::string copyString(str);
  t_helper parced = typeTaker(copyString.c_str());

  detecter(parced, copyString);
  return 0;
}
