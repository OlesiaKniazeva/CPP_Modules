#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {
}

Point::~Point() {
}

Point::Point( const float p1, const float p2 ) : x(Fixed(p1)), y(Fixed(p2)) {

}

Point::Point( const Point & rhs ) {
  *this = rhs;
}

Point& Point::operator=( const Point & rhs ) {
  x = rhs.x;
  y = rhs.y;
  return *this;
}

float Point::getX() const {
  return (x.toFloat());
}

float Point::getY() const {
  return (y.toFloat());
}
