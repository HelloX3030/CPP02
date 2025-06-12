#include "Fixed.hpp"

Fixed::Fixed()
    : raw_bits(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
    raw_bits = other.raw_bits;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other) {
        raw_bits = other.raw_bits;
    }
    return *this;
}

int Fixed::getRawBits( void) const
{
    return (raw_bits);
}

void Fixed::setRawBits( int const raw )
{
    raw_bits = raw;
}
