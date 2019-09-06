#include "examples.h"

#include <math.h>
#include <stdlib.h>

namespace Ex
{
    namespace Expressions
    {
        namespace _1_Group_Constants_Together
        {
            __NORMAL_FUNCTION
            {
                int days = 1000;
                int seconds = 24 * days * 60 * 60;
            }

            __OPTIMIZED_FUNCTION
            {
                int days = 1000;
                int seconds = days * 24 * 60 * 60;
            }
        }

        namespace _2_Use_LessExpensive_Operators
        {
            __NORMAL_FUNCTION
            {
                int x = 100;
                x = x * 9;
            }

            __OPTIMIZED_FUNCTION
            {
                int x = 100;
                x = x << 3 + x;
            }
        }

        namespace _3_Rounding_Integer_Division
        {
            __NORMAL_FUNCTION
            {
                unsigned int numerator = 100;
                unsigned int denominator = 10;
                unsigned int test = (unsigned int)round((double)numerator / denominator);
            }

            __OPTIMIZED_FUNCTION
            {
                unsigned int numerator = 100;
                unsigned int denominator = 10;

                unsigned int q = numerator / denominator;
                unsigned int r = numerator % denominator;
                unsigned int test = (r >= (denominator >> 1)) ? q + 1 : q;

                //unsigned int test = (numerator + (denominator >> 1)) / denominator;
            }
        }

        namespace _4_Double_Maybe_Better_Than_Float
        {
            __NORMAL_FUNCTION
            {
                double d, t, a = -9.8f, v0 = 0.0f, d0 = 100.0f;
                d = a*t*t + v0*t + d0;
            }

            __OPTIMIZED_FUNCTION
            {
                float d, t, a = -9.8f, v0 = 0.0f, d0 = 100.0f;
                d = a*t*t + v0*t + d0;
            }
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
