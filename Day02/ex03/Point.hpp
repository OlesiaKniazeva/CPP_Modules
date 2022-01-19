#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

  public:

  Point();
  ~Point();
  Point( const Point & rhs);
  Point( const float p1, const float p2 );

  Point& operator=( const Point & rhs );

  Point operator-( const Point & rhs);

  float getX() const;
  float getY() const;

  private:

    Fixed   x;
    Fixed   y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif