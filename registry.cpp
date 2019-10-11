#include "registry.h"

#include <iostream>

#define stringify(s) #s

#define REGISTER(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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
    ) \

#define REGISTER_1(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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

#define REGISTER_2(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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

#define REGISTER_3(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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

#define REGISTER_4(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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

#define REGISTER_5(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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

#define REGISTER_6(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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

#define REGISTER_7(_namespace, _nTime) \
	_keys.push_back(stringify(_namespace)); \
    _map.insert( \
        std::pair<std::string, FuncPtr>( \
            stringify(_namespace), \
            FuncPtr( \
				_nTime, \
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
    std::cout << "Prepare timer................ ";
    GetTimer()->setType(Timer::DurationType::MILISECONDS);
    GetTimer()->start();
    _sleep(500);
    GetTimer()->stop();

    REGISTER(Ex::CriticalStatements::_1_Expressions::_1_Group_Constants_Together, 10000000);
    REGISTER(Ex::CriticalStatements::_1_Expressions::_2_Use_LessExpensive_Operators, 10000000);
    REGISTER_1(Ex::CriticalStatements::_1_Expressions::_3_Use_Integer_Instead_Of_Float, 10000000);
    REGISTER(Ex::CriticalStatements::_2_Control_Flows::_1_Prefer_Switch_To_Compare_Integer, 10000000);
    REGISTER(Ex::CriticalStatements::_2_Control_Flows::_2_Prefer_Virtual_Function, 10000000);
    REGISTER(Ex::CriticalStatements::_3_Loops::_1_Cache_The_Loop_Value, 1000000);
    REGISTER(Ex::CriticalStatements::_3_Loops::_2_Count_Down_Instead_Of_Up, 10000000);
	REGISTER(Ex::CriticalStatements::_3_Loops::_3_More_Efficient_Loop, 1000000);
    REGISTER(Ex::CriticalStatements::_4_Functions::_1_Prefer_Return_Value_As_Output_Parameters, 100000000);
    REGISTER_1(Ex::CriticalStatements::_4_Functions::_2_Function_or_Functor_or_Lambda, 10000000);

    REGISTER(Ex::Strings::_1_First_Attempt::Eliminate_Temporary_String_Objects, 1000000);
    REGISTER(Ex::Strings::_2_Second_Attempt::Use_Better_Algorithm, 1000000);
    REGISTER(Ex::Strings::_3_Third_Attempt::Use_Character_Arrays_Instead_Of_String, 1000000);

    REGISTER(Ex::Searching::_1_Change_Data_Structure_Representing_Keys, 1000000);
    REGISTER(Ex::Searching::_2_Search_In_Sequence_Container, 1000000);
    REGISTER(Ex::Searching::_3_Optimize_Search_In_Hashed_Tables, 1000000);

    REGISTER(Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation, 1000000);
    REGISTER(Ex::Data_Structures::_1_Vector_And_String::_2_Inserting_And_Deleting, 1000000);
	REGISTER(Ex::Data_Structures::_2_Map::Inserting, 10000000);

	REGISTER_2(Ex::Input_And_Output::Reading_Files, 10000);
	REGISTER(Ex::Input_And_Output::Writing_Files, 10000);

	REGISTER(Ex::Memory_Management::_1_Placement_Without_Allocation, 1000000);
	REGISTER(Ex::Memory_Management::_2_Custom_Allocator, 1000000);
}

Registry::~Registry()
{
    _map.clear();
    ReleaseTimer();
}

FuncPtr Registry::get(std::string key)
{
    return _map.at(key);
}

std::vector<std::string> Registry::keys()
{
	return _keys;
}

Registry * Registry::_instance = nullptr;
Registry * Registry::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new Registry();
    }
    return _instance;
}

void Registry::destroyInstance()
{
    if (_instance)
    {
        delete _instance;
        _instance = nullptr;
    }
}
