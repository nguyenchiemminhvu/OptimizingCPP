#include "registry.h"

#include <iostream>

#define stringify(s) #s

Registry::Registry()
{
    _map.insert(
        std::pair<std::string, FuncPtr>(
            stringify(Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation),
            FuncPtr(
                Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation::normalFunc,
                Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation::optimized
            )
        )
    );
}

Registry::~Registry()
{
    _map.clear();
}

FuncPtr Registry::get(std::string key)
{
    return _map.at(key);
}
