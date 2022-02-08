#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <exception>
#include <cerrno>


class Conversion
{
  public:
    Conversion(const std::string & data);
    ~Conversion();
    Conversion(const Conversion & rhs);
    Conversion & operator=(const Conversion & rhs);
    void ConvertData();

  private:
    void ConvertChar();

    void CheckForSpecial();
    void ConvertSpecial();

    void CheckForInt();
    void ConvertInt();

    void CheckForFloat();
    void ConvertFloat();

    void CheckForDouble();
    void ConvertDouble();

    std::string data_;
    char letter_;
    int int_num_;
    double double_num_;
    float float_num_;
    void FindActualTypeOfData();
};

#endif