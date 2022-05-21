#pragma once

#include <cstdint>

class Bitmask
{
public:
    Bitmask();

    // Overwrites this bitmask
    void setMask(Bitmask &other);

    // Returns binary representation of bitmask
    uint32_t getMask() const;

    // Returns true if bit at pos = 1, else false
    bool getBit(int pos) const;

    // Sets bit at specified pos to 1 or 0 (true or false)
    void setBit(int pos, bool on);

    // Sets bit at pos to 1
    void setBit(int pos);

    // Sets bit at pos to 0
    void clearBit(int pos);

    // Sets all bits to 0
    void clear();

private:
    uint32_t bits;
};