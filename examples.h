#ifndef EXAMPLES_H
#define EXAMPLES_H

#define __DECLARE_FUNCTIONS_FOR_TEST \
void normalFunc(); \
void optimizedFunc();

#define __START_NORMAL_FUNCTION void normalFunc()
#define __END_NORMAL_FUNCTION

#define __START_OPTIMIZED_FUNCTION void optimizedFunc()
#define __END_OPTIMIZED_FUNCTION

namespace Ex
{
    namespace Critical_Statements
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

            namespace _3_Use_Int_Instead_Of_Float
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _4_Double_Maybe_Better_Than_Float
            {
                __DECLARE_FUNCTIONS_FOR_TEST
            }

            namespace _5_Use_Closed_Forms
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
