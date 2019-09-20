#include "examples.h"
#include "timer.h"

#include <stdlib.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

namespace Ex
{
    namespace Searching
    {
        namespace _1_Change_Data_Structure_Representing_Keys
        {
            std::map<std::string, int> map_1;

            __NORMAL_FUNCTION
            {
                map_1["111"] = 1;
                map_1["222"] = 2;
                map_1["333"] = 3;
                map_1["444"] = 4;
                map_1["555"] = 5;

                std::map<std::string, int>::iterator iter = map_1.find("555");
                if (iter != map_1.end())
                {
                    //std::cout << "found" << std::endl;
                }
                else
                {
                    //std::cout << "not found" << std::endl;
                }
            }

            template <int N = 10, typename T = char>
            class charbuf
            {
                T _data[N];
            public:
                charbuf() {}
                charbuf(const char *c) { strcpy(_data, c); }
                charbuf(const charbuf &cb) { strcpy(_data, cb._data); }
                charbuf& operator=(const charbuf& cb) { strcpy(_data, cb._data); }
                bool operator==(const charbuf& cb) const { return strcmp(_data, cb._data) == 0; }
                bool operator<(const charbuf& cb) const { return strcmp(_data, cb._data) < 0; }
            };

            template <int N = 10, typename T = char>
            bool operator<(const charbuf<N, T>& cb1, const charbuf<N, T>& cb2) {return strcmp(cb1._data, cb2._data) < 0;}

            //std::map<charbuf<>, int> map_2;

            bool compare_less_ptr(const char* ptr1, const char* ptr2)
            {
                return strcmp(ptr1, ptr2) < 0;
            }

            std::map<const char*, int, bool(*)(const char*, const char*)> map_2(compare_less_ptr);

            __OPTIMIZED_FUNCTION
            {
                map_2["111"] = 1;
                map_2["222"] = 2;
                map_2["333"] = 3;
                map_2["444"] = 4;
                map_2["555"] = 5;

                std::map<std::string, int>::iterator iter = map_1.find("555");
                if (iter != map_1.end())
                {
                    //std::cout << "found" << std::endl;
                }
                else
                {
                    //std::cout << "not found" << std::endl;
                }
            }
        }

        namespace _2_Optimize_In_Hashed_KeyValue_Tables
        {
            std::map<std::string, int> map_1;

            __NORMAL_FUNCTION
            {
                map_1["111"] = 1;
                map_1["222"] = 2;
                map_1["333"] = 3;
                map_1["444"] = 4;
                map_1["555"] = 5;

                std::map<std::string, int>::iterator iter = map_1.find("555");
                if (iter != map_1.end())
                {
                    //std::cout << "found" << std::endl;
                }
                else
                {
                    //std::cout << "not found" << std::endl;
                }
            }

            std::unordered_map<std::string, int> map_2;

            __OPTIMIZED_FUNCTION
            {
                map_2["111"] = 1;
                map_2["222"] = 2;
                map_2["333"] = 3;
                map_2["444"] = 4;
                map_2["555"] = 5;

                std::unordered_map<std::string, int>::iterator iter = map_2.find("555");
                if (iter != map_2.end())
                {
                    //std::cout << "found" << std::endl;
                }
                else
                {
                    //std::cout << "not found" << std::endl;
                }
            }
        }
    }
}
