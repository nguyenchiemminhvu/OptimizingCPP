#ifndef EXAMPLES_H
#define EXAMPLES_H

#define __DECLARE_FUNCTIONS_FOR_TEST \
void normalFunc(); \
void optimized_1(); \
void optimized_2(); \
void optimized_3(); \
void optimized_4(); \
void optimized_5(); \
void optimized_6(); \
void optimized_7(); \

#define __NORMAL_FUNCTION void normalFunc()
#define __OPTIMIZED_FUNCTION_1 void optimized_1()
#define __OPTIMIZED_FUNCTION_2 void optimized_2()
#define __OPTIMIZED_FUNCTION_3 void optimized_3()
#define __OPTIMIZED_FUNCTION_4 void optimized_4()
#define __OPTIMIZED_FUNCTION_5 void optimized_5()
#define __OPTIMIZED_FUNCTION_6 void optimized_6()
#define __OPTIMIZED_FUNCTION_7 void optimized_7()

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
        namespace _1_Prefer_Switch_To_Compare_Integer
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _2_Prefer_Virtual_Function
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }
    }

    namespace Loops
    {
        namespace _1_Cache_The_Loop_Value
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _2_Count_Down_Instead_Of_Up
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _3_Remove_Hidden_Function_Call
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }
    }

    namespace Functions
    {
        namespace _1_Grouping_Function_Arguments
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _2_Prefer_Return_Value_As_Output_Parameters
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }
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
        namespace _1_First_Attempt
        {
            namespace _1_Eliminate_Temporary_String_Objects
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _2_Eliminate_Return_String_Value
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }
        }

        namespace _2_Second_Attempt
        {
            namespace _1_Use_Better_Algorithm
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }
        }

        namespace _3_Use_Character_Arrays_Instead_Of_String
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }
    }

    namespace Searching
    {
        namespace _1_Change_Data_Structure_Representing_Keys
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _2_Search_In_Sequence_Container
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }

        namespace _3_Optimize_Search_In_Hashed_Tables
        {
            __DECLARE_FUNCTIONS_FOR_TEST
        }
    }

    namespace Data_Structures
    {
        namespace _1_Vector_And_String
        {
            namespace _1_Reallocation
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _2_Inserting_And_Deleting
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _3_Iterating
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _4_Sorting
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _5_Lookup
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }
        }

        namespace _2_Deque
        {

        }

        namespace _3_List
        {

        }

        namespace _4_Forward_List
        {

        }

        namespace _5_Map_And_Multimap
        {

        }

        namespace _6_Set_And_Multiset
        {

        }
    }

    namespace Input_And_Output
    {

    }

    namespace Memory_Management
    {

    }

    namespace Metaprogramming
    {

    }

    namespace Use_Better_Libraries
    {

    }

    namespace Use_Libraries_Better
    {

    }
}

#endif // EXAMPLES_H
