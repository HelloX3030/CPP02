#include "Fixed.hpp"

Fixed::Fixed()
    : raw_bits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    raw_bits = other.raw_bits;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        raw_bits = other.raw_bits;
    }
    return *this;
}

int Fixed::getRawBits( void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (raw_bits);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    raw_bits = raw;
}
