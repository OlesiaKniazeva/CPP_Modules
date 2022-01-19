#include "Fixed.hpp"



int main( void )
{
  {
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "------" << std::endl;
  }
  {
    Fixed a (12.56f);
    Fixed c (a);
    Fixed b (13);
    Fixed d (0.5f);
    Fixed e (2);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a - c = " << a - c << std::endl;
    std::cout << "d * e = " << d * e << std::endl;
    std::cout << "b / e = " << b / e << std::endl;
    std::cout << a << " more than " << b << " : " << std::boolalpha <<  (a > b) << std::endl;
    std::cout << a << " less than " << b << " : " << std::boolalpha <<  (a < b) << std::endl;
    std::cout << a << " less or equal to " << c << " : " << std::boolalpha <<  (a <= c) << std::endl;
    std::cout << a << " is equal " << b << " : " << std::boolalpha <<  (a == b) << std::endl;
    std::cout << a << " is equal " << c << " : " << std::boolalpha <<  (a == c) << std::endl;
    return 0;
  }
}