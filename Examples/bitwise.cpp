#include "examples.h"

namespace Ex
{
    namespace Bitwise
    {
        namespace _1_Check_Power_Of_Two
        {
            inline bool checkPowerOfTwo_1(unsigned int value)
            {
                int countBitOne = 0;
                while (value)
                {
                    if (value & 1)
                    {
                        countBitOne++;
                    }
                    value >>= 1;
                }
                return countBitOne == 1;
            }

            inline bool checkPowerOfTwo_2(unsigned int value)
            {
                return (value != 0) && !(value & (value - 1));
            }

            __NORMAL_FUNCTION
            {
                bool isPowerOfTwo = checkPowerOfTwo_1(32);
            }

            __OPTIMIZED_FUNCTION
            {
                bool isPowerOfTwo = checkPowerOfTwo_2(32);
            }
        }

        namespace _2_Add_One
        {
            __NORMAL_FUNCTION
            {
                int a = 0;
                a++;
            }

            __OPTIMIZED_FUNCTION
            {
                int a = 0;
                a = (-(~a));
            }
        }
    }
}
