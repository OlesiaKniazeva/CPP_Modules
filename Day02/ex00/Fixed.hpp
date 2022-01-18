#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
	public:

		Fixed();
		~Fixed();
    Fixed(const Fixed & rhs);

    Fixed& operator=(Fixed const & rhs);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

  private:

  int               fixed_point_;
  static const int  fractional_bits_ = 8;

};

#endif