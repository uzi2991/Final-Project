#include "Utility/Bitmask.hpp"

Bitmask::Bitmask() : bits(0) {}

void Bitmask::setMask(Bitmask &other)
{
    this->bits = other.getMask();
}

uint32_t Bitmask::getMask() const
{
    return this->bits;
}

bool Bitmask::getBit(int pos) const
{
    return (this->bits & (1 << pos)) != 0;
}

void Bitmask::setBit(int pos, bool on)
{
    if (on)
    {
        this->setBit(pos);
    }
    else
    {
        this->clearBit(pos);
    }
}

void Bitmask::setBit(int pos)
{
    this->bits = this->bits | 1 << pos; 
}

void Bitmask::clearBit(int pos)
{
    this->bits = this->bits & ~(1 << pos); 
}

void Bitmask::clear()
{
    this->bits = 0;
}