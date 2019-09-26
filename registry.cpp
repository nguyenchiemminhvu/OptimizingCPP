#include "registry.h"

#include <iostream>

#define stringify(s) #s

#define REGISTER(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr \
            ) \
        ) \
    )

#define REGISTER_1(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                _namespace::optimized_1, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr \
            ) \
        ) \
    )

#define REGISTER_2(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                _namespace::optimized_1, \
                _namespace::optimized_2, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr \
            ) \
        ) \
    )

#define REGISTER_3(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                _namespace::optimized_1, \
                _namespace::optimized_2, \
                _namespace::optimized_3, \
                nullptr, \
                nullptr, \
                nullptr, \
                nullptr \
            ) \
        ) \
    )

#define REGISTER_4(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                _namespace::optimized_1, \
                _namespace::optimized_2, \
                _namespace::optimized_3, \
                _namespace::optimized_4, \
                nullptr, \
                nullptr, \
                nullptr \
            ) \
        ) \
    )

#define REGISTER_5(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                _namespace::optimized_1, \
                _namespace::optimized_2, \
                _namespace::optimized_3, \
                _namespace::optimized_4, \
                _namespace::optimized_5, \
                nullptr, \
                nullptr \
            ) \
        ) \
    )

#define REGISTER_6(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                _namespace::optimized_1, \
                _namespace::optimized_2, \
                _namespace::optimized_3, \
                _namespace::optimized_4, \
                _namespace::optimized_5, \
                _namespace::optimized_6, \
                nullptr \
            ) \
        ) \
    )

#define REGISTER_7(_namespace) \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
                _namespace::normalFunc, \
                _namespace::optimized, \
                _namespace::optimized_1, \
                _namespace::optimized_2, \
                _namespace::optimized_3, \
                _namespace::optimized_4, \
                _namespace::optimized_5, \
                _namespace::optimized_6, \
                _namespace::optimized_7 \
            ) \
        ) \
    )

Registry::Registry()
{
    REGISTER(Ex::CriticalStatements::_1_Expressions::_1_Group_Constants_Together);
    REGISTER(Ex::CriticalStatements::_1_Expressions::_2_Use_LessExpensive_Operators);
    REGISTER(Ex::CriticalStatements::_1_Expressions::_3_Rounding_Integer_Division);
    REGISTER(Ex::CriticalStatements::_1_Expressions::_4_Double_Maybe_Better_Than_Float);
    REGISTER(Ex::CriticalStatements::_2_Control_Flows::_1_Prefer_Switch_To_Compare_Integer);
    REGISTER(Ex::CriticalStatements::_2_Control_Flows::_2_Prefer_Virtual_Function);
    REGISTER(Ex::CriticalStatements::_3_Loops::_1_Cache_The_Loop_Value);
    REGISTER(Ex::CriticalStatements::_3_Loops::_2_Count_Down_Instead_Of_Up);
    REGISTER(Ex::CriticalStatements::_3_Loops::_3_Remove_Hidden_Function_Call);
    REGISTER(Ex::CriticalStatements::_4_Functions::_1_Grouping_Function_Arguments);
    REGISTER(Ex::CriticalStatements::_4_Functions::_2_Prefer_Return_Value_As_Output_Parameters);

    REGISTER(Ex::Bitwise::_1_Check_Power_Of_Two);
    REGISTER(Ex::Bitwise::_2_Add_One);

    REGISTER(Ex::Strings::_1_First_Attempt::_1_Eliminate_Temporary_String_Objects);
    REGISTER(Ex::Strings::_1_First_Attempt::_2_Eliminate_Return_String_Value);
    REGISTER(Ex::Strings::_2_Second_Attempt::_1_Use_Better_Algorithm);
    REGISTER(Ex::Strings::_3_Use_Character_Arrays_Instead_Of_String);

    REGISTER(Ex::Searching::_1_Change_Data_Structure_Representing_Keys);
    REGISTER(Ex::Searching::_2_Search_In_Sequence_Container);
    REGISTER(Ex::Searching::_3_Optimize_Search_In_Hashed_Tables);

    REGISTER(Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation);
    REGISTER(Ex::Data_Structures::_1_Vector_And_String::_2_Inserting_And_Deleting);
    REGISTER(Ex::Data_Structures::_1_Vector_And_String::_3_Iterating);
    REGISTER(Ex::Data_Structures::_1_Vector_And_String::_4_Sorting);
    REGISTER(Ex::Data_Structures::_1_Vector_And_String::_5_Lookup);
}

Registry::~Registry()
{
    _map.clear();
}

FuncPtr Registry::get(std::string key)
{
    return _map.at(key);
}
