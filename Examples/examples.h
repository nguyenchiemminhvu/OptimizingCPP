#ifndef EXAMPLES_H
#define EXAMPLES_H

#define __DECLARE_FUNCTIONS_FOR_TEST \
void normalFunc(); \
void optimizedFunc();

#define __NORMAL_FUNCTION void normalFunc()

#define __OPTIMIZED_FUNCTION void optimizedFunc()

namespace Ex
{
    namespace Expressions
    {
        namespace _1_Group_Constants_Together
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _2_Use_LessExpensive_Operators
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _3_Rounding_Integer_Division
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _4_Double_Maybe_Better_Than_Float
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }
    }

    namespace Control_Flows
    {

    }

    namespace Loops
    {

    }

    namespace Functions
    {

    }

    namespace Bitwise
    {
        namespace _1_Check_Power_Of_Two
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _2_Add_One
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }
    }

    namespace Strings
    {

    }

    namespace Searching
    {

    }

    namespace Sorting
    {

    }

    namespace Input_And_Output
    {

    }

    namespace Memory_Management
    {

    }

    namespace STL
    {

    }

    namespace Metaprogramming
    {

    }
}

#endif // EXAMPLES_H
