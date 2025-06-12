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

        // Functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
