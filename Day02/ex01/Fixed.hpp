#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
	public:

		Fixed();
    Fixed( const int num );
    Fixed( const float num );
		~Fixed();
    Fixed(const Fixed & rhs);

    Fixed& operator=(Fixed const & rhs);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

  private:

  int               fixed_point_;
  static const int  bits_ = 8;

};

std::ostream& operator<<(std::ostream& output, const Fixed & rhs);

#endif