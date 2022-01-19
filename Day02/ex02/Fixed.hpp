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
    Fixed( const Fixed & rhs );

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat( void ) const;
    int toInt( void ) const;

    Fixed& operator=( Fixed const & rhs );

    bool operator>( Fixed const & rhs );
    bool operator<( Fixed const & rhs );
    bool operator>=( Fixed const & rhs );
    bool operator<=( Fixed const & rhs );
    bool   operator==( Fixed const & rhs );
    bool   operator!=( Fixed const & rhs );

    Fixed operator+( Fixed const & rhs );
    Fixed operator-( Fixed const & rhs );
    Fixed operator*( Fixed const & rhs );
    Fixed operator/( Fixed const & rhs );

    Fixed& operator++( void );
    Fixed& operator--( void );

    Fixed operator++( int );
    Fixed operator--( int );


    static const Fixed& min( const Fixed & lhs, const Fixed & rhs );
    static const Fixed& max( const Fixed & lhs, const Fixed & rhs );
    static  Fixed& min( Fixed & lhs, Fixed & rhs );
    static  Fixed& max( Fixed & lhs, Fixed & rhs );

  private:

  int               fixed_point_;
  static const int  bits_ = 8;

};

std::ostream & operator<<(std::ostream& output, const Fixed & rhs);

#endif