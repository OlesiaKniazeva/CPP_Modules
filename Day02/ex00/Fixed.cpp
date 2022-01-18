#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = rhs;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
  std::cout << "Assignation operator called"  << std::endl;
  fixed_point_ = rhs.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return (fixed_point_);
}

void Fixed::setRawBits(int const raw)
{
  std::cout << "setRawBits member function called" << std::endl;
  fixed_point_ = raw;
}
