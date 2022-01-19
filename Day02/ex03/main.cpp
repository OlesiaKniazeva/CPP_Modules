#include "Point.hpp"

void CheckPoint(const Point & x,const Point & y, const Point & z, const Point & search)
{
  if (bsp(x, y, z, search)) {
      std::cout << "Point inside triangle" << std::endl;
    }
    else {
      std::cout << "Point outside triangle"<< std::endl;
    }
}

int main( void )
{
    Point x;
    Point y(1.2f, 5.6f);
    Point z(6, 6);
    Point search(2, 3);

    CheckPoint(x, y, z, search);
    CheckPoint(Point(3, 4), Point(7.5, 8.8), Point(2.4, 9.6), Point(0, 0));
    CheckPoint(Point(2, 0), Point(5, 0), Point(2, 9), Point(4, 0));

    return 0;
}