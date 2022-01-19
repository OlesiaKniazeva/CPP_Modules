#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_(0) {

}

Fixed::Fixed( const int num ) : fixed_point_((int)num << bits_) {

}

Fixed::Fixed( const float num ) {
  fixed_point_ = (int)roundf(num * (1 << bits_));
}

Fixed::~Fixed() {
}

Fixed::Fixed( const Fixed & rhs ) {
  *this = rhs;
}

int Fixed::getRawBits( void ) const {
  return fixed_point_;
}

void  Fixed::setRawBits( int const raw ) {
  fixed_point_ = raw;
}

float Fixed::toFloat( void ) const {
  return (float)fixed_point_ / (float)(1 << bits_);
}

int Fixed::toInt( void ) const {
  return (int)(fixed_point_ >> bits_);
}

Fixed& Fixed::operator=( Fixed const & rhs ) {
  fixed_point_ = rhs.fixed_point_;
  return *this;
}

std::ostream & operator<<(std::ostream& output, const Fixed & rhs) {
  output << rhs.toFloat();
  return output;
}

Fixed Fixed::operator+( Fixed const & rhs ) {
  Fixed n;
  n.setRawBits(fixed_point_ + rhs.fixed_point_);
  return n;
}

Fixed Fixed::operator-( Fixed const & rhs ) {
  Fixed n;
  n.setRawBits(fixed_point_ - rhs.fixed_point_);
  return n;
}

Fixed Fixed::operator*( Fixed const & rhs ) {
  Fixed n;
  n.setRawBits((fixed_point_ * rhs.fixed_point_) >> bits_);
  return n;
}

Fixed Fixed::operator/( Fixed const & rhs ) {
  Fixed n;
  n.setRawBits((fixed_point_  << bits_) / rhs.fixed_point_);
  return n;
}


bool Fixed::operator>( Fixed const & rhs ) {
  return (fixed_point_ > rhs.fixed_point_);
}

bool Fixed::operator<( Fixed const & rhs ) {
  return (fixed_point_ < rhs.fixed_point_);
}

bool Fixed::operator<=( Fixed const & rhs ) {
  return (fixed_point_ <= rhs.fixed_point_);
}

bool Fixed::operator>=( Fixed const & rhs ) {
  return (fixed_point_ >= rhs.fixed_point_);
}

bool   Fixed::operator==( Fixed const & rhs ) {
  return (fixed_point_ == rhs.fixed_point_);
}

bool   Fixed::operator!=( Fixed const & rhs ) {
  return !(*this == rhs);
}

// версия префикс (++x, --y)

Fixed& Fixed::operator++( void ) {
  fixed_point_++;
  return (*this);
}

Fixed& Fixed::operator--( void ) {
  fixed_point_--;
  return (*this);
}

// версия постфикс ( x++, y--)

Fixed Fixed::operator++( int ) {
  Fixed temp(*this);
  ++(*this);
  return (temp);
}

Fixed Fixed::operator--( int ) {
  Fixed temp(*this);
  --(*this);
  return (temp);
}

const Fixed& Fixed::min( const Fixed & lhs, const Fixed & rhs ) {
  if (lhs.fixed_point_ < rhs.fixed_point_) {
    return (lhs);
  }
  else {
    return (rhs);
  }
}

const Fixed& Fixed::max( const Fixed & lhs, const Fixed & rhs ) {
    if (lhs.fixed_point_ > rhs.fixed_point_) {
    return (lhs);
  }
  else {
    return (rhs);
  }
}

Fixed& Fixed::min( Fixed & lhs, Fixed & rhs ) {
  if (lhs < rhs) {
    return (lhs);
  }
  else {
    return (rhs);
  }
}

Fixed& Fixed::max( Fixed & lhs, Fixed & rhs ) {
    if (lhs > rhs) {
    return (lhs);
  }
  else {
    return (rhs);
  }
}