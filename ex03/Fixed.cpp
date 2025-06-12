#include "Fixed.hpp"

Fixed::Fixed()
    : raw_bits(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    raw_bits = value << fractional_bits;
}

Fixed::Fixed(const float value)
{
    // std::cout << "Float constructor called" << std::endl;
    raw_bits = static_cast<int>(roundf(value * (1 << fractional_bits)));
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    raw_bits = other.raw_bits;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        raw_bits = other.raw_bits;
    }
    return *this;
}

bool Fixed::operator>(const Fixed& other)
{
    return (raw_bits > other.raw_bits);
}

bool Fixed::operator<(const Fixed& other)
{
    return (raw_bits < other.raw_bits);
}

bool Fixed::operator>=(const Fixed& other)
{
    return (raw_bits >= other.raw_bits);
}

bool Fixed::operator<=(const Fixed& other)
{
    return (raw_bits <= other.raw_bits);
}

bool Fixed::operator==(const Fixed& other)
{
    return (raw_bits == other.raw_bits);
}

bool Fixed::operator!=(const Fixed& other)
{
    return (raw_bits != other.raw_bits);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->raw_bits + other.raw_bits);
    return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->raw_bits - other.raw_bits);
    return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    long long temp = static_cast<long long>(raw_bits) * other.raw_bits;
    result.setRawBits(static_cast<int>(temp >> fractional_bits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    long long temp = (static_cast<long long>(raw_bits) << fractional_bits) / other.raw_bits;
    result.setRawBits(static_cast<int>(temp));
    return result;
}

Fixed& Fixed::operator++()
{
    raw_bits++;
    return (*this);
}

Fixed& Fixed::operator--()
{
    raw_bits--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}


Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1.raw_bits < f2.raw_bits)
        return (f1);
    else
        return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1.raw_bits < f2.raw_bits)
        return (f1);
    else
        return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1.raw_bits > f2.raw_bits)
        return (f1);
    else
        return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1.raw_bits > f2.raw_bits)
        return (f1);
    else
        return (f2);
}

int Fixed::getRawBits( void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (raw_bits);
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
    raw_bits = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(raw_bits) / (1 << fractional_bits);
}

int Fixed::toInt( void ) const
{
    return raw_bits >> fractional_bits;
}
