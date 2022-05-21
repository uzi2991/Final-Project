#pragma once

#include <array>
#include <bitset>

class Entity;
class Component;

using ComponentTypeID = std::size_t;

inline ComponentTypeID getUniqueComponentID()
{
    static ComponentTypeID lastID = 0u;
    return lastID++;
}

template <class T>
inline ComponentTypeID getComponentTypeID()
{
    static_assert(std::is_base_of<Component, T>::value, "T must be a Component\n");
    static const ComponentTypeID typeID = getUniqueComponentID();
    return typeID;
}

constexpr std::size_t MAX_ENTITIES = 5000;
constexpr std::size_t MAX_COMPONENTS = 32;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<Component*, MAX_COMPONENTS>;
