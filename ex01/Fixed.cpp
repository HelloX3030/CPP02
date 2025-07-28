#include "Fixed.hpp"

Fixed::Fixed()
    : raw_bits(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    raw_bits = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    raw_bits = static_cast<int>(roundf(value * (1 << fractional_bits)));
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

float Fixed::toFloat( void ) const
{
    return static_cast<float>(raw_bits) / (1 << fractional_bits);
}

int Fixed::toInt( void ) const
{
    return raw_bits >> fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
