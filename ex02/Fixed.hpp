#pragma once

#include <iostream>

class Fixed
{
    private:
        int raw_bits;
        static const int fractional_bits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);

        // comparison
        bool operator>(const Fixed& other);
        bool operator<(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);

        // arithmetic
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        
        // increments
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int); 
        Fixed operator--(int);

        // Functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
