#include "examples.h"
#include "randomgenerator.h"

#include <typeinfo>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>

#define stringify(s) #s

namespace Ex
{
    namespace Data_Structures
    {
        struct KeyValue
        {
            char _key[10];
            int _value;

            KeyValue()
            {
            }

            KeyValue(const int &value)
                : _value(value)
            {
                strcpy(_key, stringify(value));
            }

            KeyValue(const char *key, const int &value)
                : _value(value)
            {
                strcpy(_key, key);
            }

            KeyValue & operator = (const KeyValue &kv)
            {
                if (this == &kv)
                    return *this;

                strcpy(_key, kv._key);
                _value = kv._value;
                return *this;
            }

            bool operator < (const KeyValue &kv) { return strcmp(_key, kv._key) < 0; }
            bool operator == (const KeyValue &kv) { return strcmp(_key, kv._key) == 0; }
        };

        bool compare_KeyValue(const KeyValue &kv1, const KeyValue &kv2)
        {
            return strcmp(kv1._key, kv2._key) < 0;
        }

        namespace _1_Vector_And_String
        {
            namespace _1_Reallocation
            {
                std::vector<KeyValue> createVec_1()
                {
                    std::vector<KeyValue> _vec;
                    for (int i = 0; i < 10; i++)
                    {
                        _vec.push_back(KeyValue(RANDOM()));
                    }
                    return _vec;
                }

                __NORMAL_FUNCTION
                {
                    std::vector<KeyValue> vec_1 = createVec_1();
                }

                std::vector<KeyValue> createVec_2()
                {
                    std::vector<KeyValue> _vec;
                    _vec.reserve(10);
                    for (int i = 0; i < 10; i++)
                    {
                        _vec.push_back(KeyValue(RANDOM()));
                    }
                    return _vec;
                }

                __OPTIMIZED_FUNCTION__
                {
                    std::vector<KeyValue> vec_2 = createVec_2();
                }
            }

            namespace _2_Inserting_And_Deleting
            {
                std::vector<KeyValue> createVec_1()
                {
                    std::vector<KeyValue> _vec;
                    for (int i = 0; i < 10; i++)
                    {
                        _vec.push_back(KeyValue(RANDOM()));
                    }
                    return _vec;
                }

                __NORMAL_FUNCTION
                {
                    std::vector<KeyValue> vec_1 = createVec_1();
                }

                std::vector<KeyValue> temp = createVec_1();
                __OPTIMIZED_FUNCTION__
                {
                    std::vector<KeyValue> vec_2;
                    vec_2.insert(vec_2.end(), temp.begin(), temp.end());
                }

                __OPTIMIZED_FUNCTION_1
                {
                    std::vector<KeyValue> vec_3;
                    vec_3.reserve(temp.size());
                    for (int i = 0; i < temp.size(); i++)
                    {
                        vec_3.push_back(temp[i]);
                    }
                }
            }

            namespace _3_Iterating
            {
                std::vector<KeyValue> createVec()
                {
                    std::vector<KeyValue> _vec;
                    for (int i = 0; i < 100; i++)
                    {
                        _vec.push_back(KeyValue(RANDOM()));
                    }
                    return _vec;
                }

                std::vector<KeyValue> vec_1 = createVec();

                __NORMAL_FUNCTION
                {
                    for (std::vector<KeyValue>::iterator i = vec_1.begin(); i != vec_1.end(); i++)
                    {
                    }
                }

                std::vector<KeyValue> vec_2 = createVec();

                __OPTIMIZED_FUNCTION__
                {
                    for (int i = 0; i < vec_2.size(); i++)
                    {
                    }
                }
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
}
