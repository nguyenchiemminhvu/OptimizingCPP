#include "examples.h"

#include <stdlib.h>
#include <string.h>
#include <map>
#include <string>
#include <vector>

namespace Ex
{
    namespace Searching
    {
        namespace _1_Use_STD_Map
        {
            std::map<std::string, int> map_1;

            __NORMAL_FUNCTION
            {

            }

            template <int N = 10, typename T = char>
            class charbuf
            {
                T _data[N];
            public:
                charbuf() {}
                charbuf(const charbuf &cb) {}
                charbuf& operator=(const charbuf& cb) {}
                bool operator==(const charbuf& cb) const {return true;}
                bool operator<(const charbuf& cb) const {return true;}
            };

            template <int N = 10, typename T = char>
            bool operator<(const charbuf<N, T>& cb1, const charbuf<N, T>& cb2) {return true;}

            std::map<charbuf<>, int> map_2;

            __OPTIMIZED_FUNCTION
            {

            }
        }

        namespace _2_Use_Algorithm_Header
        {
            __NORMAL_FUNCTION
            {

            }

            __OPTIMIZED_FUNCTION
            {

            }
        }

        namespace _3_Optimize_In_Hashed_KeyValue_Tables
        {
            __NORMAL_FUNCTION
            {

            }

            __OPTIMIZED_FUNCTION
            {

            }
        }
    }
}
