#include "Point.hpp"

float type( Point const start, Point const end, Point const point ) {
  float type = (start.getX() - point.getX()) * (end.getY() - start.getY())
          - (end.getX() - start.getX()) * (start.getY() - point.getY());
  return (type);
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
  float t1 = type(a, b, point);
  float t2 = type(b, c, point);
  float t3 = type(c, a, point);
  return ((t1 < 0 && t2 < 0 && t3 < 0) || (t1 > 0 && t2 > 0 && t3 > 0));
}