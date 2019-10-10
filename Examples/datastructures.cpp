#include "examples.h"
#include "../randomgenerator.h"

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
                __NORMAL_FUNCTION
                {
					std::vector<KeyValue> vec_1;
					for (int i = 0; i < 10; i++)
					{
						vec_1.push_back(KeyValue(RANDOM()));
					}
                }

                __OPTIMIZED_FUNCTION__
                {
					std::vector<KeyValue> vec_2;
					vec_2.reserve(10);
					for (int i = 0; i < 10; i++)
					{
						vec_2.push_back(KeyValue(RANDOM()));
					}
                }
            }

            namespace _2_Inserting_And_Deleting
            {
                std::vector<KeyValue> createVec()
                {
                    std::vector<KeyValue> _vec;
                    for (int i = 0; i < 10; i++)
                    {
                        _vec.push_back(KeyValue(RANDOM()));
                    }
                    return _vec;
                }
				std::vector<KeyValue> temp = createVec();

                __NORMAL_FUNCTION
                {
					std::vector<KeyValue> vec_1;
					vec_1.reserve(temp.size());
					for (int i = 0; i < 10; i++)
					{
						vec_1.push_back(KeyValue(RANDOM()));
					}
                }

                __OPTIMIZED_FUNCTION__
                {
					std::vector<KeyValue> vec_2;
					vec_2.insert(vec_2.end(), temp.begin(), temp.end());
                }
            }
        }

        namespace _2_Map
        {
			namespace Inserting
			{
				std::vector<KeyValue> createVec()
				{
					std::vector<KeyValue> _vec;
					_vec.reserve(100);
					for (int i = 0; i < _vec.size(); i++)
					{
						_vec.push_back(KeyValue(RANDOM()));
					}
					std::stable_sort(_vec.begin(), _vec.end(), compare_KeyValue);
					return _vec;
				}

				std::vector<KeyValue> temp = createVec();

				std::map<std::string, int> map_1;
				std::vector<KeyValue> vec_1 = temp;
				__NORMAL_FUNCTION
				{
					for (int i = 0; i < vec_1.size(); i++)
					{
						map_1.insert(std::pair<std::string, int>(vec_1[i]._key, vec_1[i]._value));
					}
				}

				std::map<std::string, int> map_2;
				std::vector<KeyValue> vec_2 = temp;
				__OPTIMIZED_FUNCTION__
				{
					auto hint = map_2.end();
					for (int i = 0; i < vec_2.size(); i++)
					{
						hint = map_2.insert(hint, std::pair<char *, int>(vec_2[i]._key, vec_2[i]._value));
					}
				}
			}
        }
    }
}
