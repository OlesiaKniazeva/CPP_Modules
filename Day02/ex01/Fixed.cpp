#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int num ) : fixed_point_(num << bits_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &rhs) {
  std::cout << "Copy constructor called" << std::endl;
  *this = rhs;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const float num ) {
  std::cout << "Float constructor called" << std::endl;
  fixed_point_ = static_cast<int>(roundf(num *  (1 << bits_)));
}

int Fixed::getRawBits() const {
  return fixed_point_;
}

void Fixed::setRawBits( int const raw ) {
  fixed_point_ = raw;
}

int Fixed::toInt() const {
  return static_cast<int>(fixed_point_ >> bits_);

}

float Fixed::toFloat() const {
  float fl = static_cast<float>(fixed_point_) / (1 << bits_);
  return fl;
}

Fixed& Fixed::operator=(Fixed const &rhs)
{
  std::cout << "Assignation operator called"  << std::endl;
  fixed_point_ = rhs.getRawBits();
  return *this;
}

std::ostream& operator<<(std::ostream& output, const Fixed & rhs)
{
  output << rhs.toFloat();
  return output;
}
