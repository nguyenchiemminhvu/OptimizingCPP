#include "examples.h"
#include "timer.h"

#include <stdlib.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <array>

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

            std::map<charbuf<>, int> map_2;

            __OPTIMIZED_FUNCTION_1
            {
                map_2["111"] = 1;
                map_2["222"] = 2;
                map_2["333"] = 3;
                map_2["444"] = 4;
                map_2["555"] = 5;
            }

            bool compare_less_ptr(const char* ptr1, const char* ptr2)
            {
                return strcmp(ptr1, ptr2) < 0;
            }

            std::map<const char*, int, bool(*)(const char*, const char*)> map_3(compare_less_ptr);

            __OPTIMIZED_FUNCTION_2
            {
                map_3["111"] = 1;
                map_3["222"] = 2;
                map_3["333"] = 3;
                map_3["444"] = 4;
                map_3["555"] = 5;
            }
        }

        namespace _2_Search_In_Sequence_Container
        {
            std::map<std::string, int> createMap_1()
            {
                std::map<std::string, int> _map;
                _map["111"] = 1;
                _map["222"] = 2;
                _map["333"] = 3;
                _map["444"] = 4;
                _map["555"] = 5;
                return _map;
            }

            std::map<std::string, int> map_1 = createMap_1();
            std::map<std::string, int>::iterator MapIter;

            __NORMAL_FUNCTION
            {
                MapIter = map_1.find("555");
                if (MapIter != map_1.end())
                {
                    //std::cout << "Found" << std::endl;
                }
                else
                {
                    //std::cout << "Not found" << std::endl;
                }
            }

            struct KeyValue
            {
                const char* key;
                int value;

                KeyValue() {}
                KeyValue(const char *k, int v) { key = k; value = v; }
                KeyValue(const KeyValue &kv) { key = kv.key; value = kv.value; }

                bool operator == (const KeyValue &kv) { return strcmp(key, kv.key) == 0; }
                bool operator < (const KeyValue &kv) { return strcmp(key, kv.key) < 0; }
            };

            bool operator == (const KeyValue &kv1, const KeyValue &kv2) { return strcmp(kv1.key, kv2.key) == 0; }
            bool operator < (const KeyValue &kv1, const KeyValue &kv2) { return strcmp(kv1.key, kv2.key) < 0; }

            std::vector<KeyValue> createVec_1()
            {
                std::vector<KeyValue> _set;
                _set.push_back(KeyValue("111", 1));
                _set.push_back(KeyValue("222", 2));
                _set.push_back(KeyValue("333", 3));
                _set.push_back(KeyValue("444", 4));
                _set.push_back(KeyValue("555", 5));
                return _set;
            }

            std::vector<KeyValue> vec_1 = createVec_1();
            std::vector<KeyValue>::iterator VecIter;

            __OPTIMIZED_FUNCTION_1
            {
                VecIter = std::find(vec_1.begin(), vec_1.end(), KeyValue("555", 5));
                if (VecIter != vec_1.end())
                {
                    //std::cout << "Found" << std::endl;
                }
                else
                {
                    //std::cout << "Not found" << std::endl;
                }
            }

            __OPTIMIZED_FUNCTION_2
            {

            }

            __OPTIMIZED_FUNCTION_3
            {

            }
        }

        namespace _5_Optimize_Search_In_Hashed_Tables
        {
            std::map<std::string, int> createMap_1()
            {
                std::map<std::string, int> _map;
                _map["111"] = 1;
                _map["222"] = 2;
                _map["333"] = 3;
                _map["444"] = 4;
                _map["555"] = 5;
                return _map;
            }

            std::map<std::string, int> map_1 = createMap_1();

            __NORMAL_FUNCTION
            {
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

            std::unordered_map<std::string, int> createMap_2()
            {
                std::unordered_map<std::string, int> _map;
                _map["111"] = 1;
                _map["222"] = 2;
                _map["333"] = 3;
                _map["444"] = 4;
                _map["555"] = 5;
                return _map;
            }

            std::unordered_map<std::string, int> map_2;

            __OPTIMIZED_FUNCTION_1
            {
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
