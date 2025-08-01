#pragma once

#include <iostream>

class Fixed
{
    private:
        int raw_bits;
        static const int fractional_bits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);

        // Functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
