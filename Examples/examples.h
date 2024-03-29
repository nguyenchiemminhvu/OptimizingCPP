#ifndef EXAMPLES_H
#define EXAMPLES_H

#define __DECLARE_FUNCTIONS_FOR_TEST \
void normalFunc();  \
void optimized();   \
void optimized_1(); \
void optimized_2(); \
void optimized_3(); \
void optimized_4(); \
void optimized_5(); \
void optimized_6(); \
void optimized_7(); \

#define __NORMAL_FUNCTION      void normalFunc()
#define __OPTIMIZED_FUNCTION__ void optimized()
#define __OPTIMIZED_FUNCTION_1 void optimized_1()
#define __OPTIMIZED_FUNCTION_2 void optimized_2()
#define __OPTIMIZED_FUNCTION_3 void optimized_3()
#define __OPTIMIZED_FUNCTION_4 void optimized_4()
#define __OPTIMIZED_FUNCTION_5 void optimized_5()
#define __OPTIMIZED_FUNCTION_6 void optimized_6()
#define __OPTIMIZED_FUNCTION_7 void optimized_7()

namespace Ex
{
    namespace CriticalStatements
    {
        namespace _1_Expressions
        {
            namespace _1_Group_Constants_Together
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _2_Use_LessExpensive_Operators
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _3_Use_Integer_Instead_Of_Float
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }
        }

        namespace _2_Control_Flows
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

        namespace _3_Loops
        {
            namespace _1_Cache_The_Loop_Value
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _2_Count_Down_Instead_Of_Up
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

			namespace _3_More_Efficient_Loop
			{
				__DECLARE_FUNCTIONS_FOR_TEST
			}
        }

        namespace _4_Functions
        {
            namespace _1_Prefer_Return_Value_As_Output_Parameters
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

			namespace _2_Function_or_Functor_or_Lambda
			{
				__DECLARE_FUNCTIONS_FOR_TEST
			}
        }
    }

    namespace Strings
    {
        namespace _1_First_Attempt
        {
            namespace Eliminate_Temporary_String_Objects
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }
        }

        namespace _2_Second_Attempt
        {
            namespace Use_Better_Algorithm
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }
        }

        namespace _3_Third_Attempt
        {
			namespace Use_Character_Arrays_Instead_Of_String
			{
				__DECLARE_FUNCTIONS_FOR_TEST
			}
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
        }

        namespace _2_Map
        {
			namespace Inserting
			{
				__DECLARE_FUNCTIONS_FOR_TEST
			}
        }
    }

    namespace Input_And_Output
    {
		namespace Reading_Files
		{
			__DECLARE_FUNCTIONS_FOR_TEST
		}

		namespace Writing_Files
		{
			__DECLARE_FUNCTIONS_FOR_TEST
		}
    }

    namespace Memory_Management
    {
		namespace _1_Placement_Without_Allocation
		{
			__DECLARE_FUNCTIONS_FOR_TEST
		}

		namespace _2_Custom_Allocator
		{
			__DECLARE_FUNCTIONS_FOR_TEST
		}
    }
}

#endif // EXAMPLES_H
