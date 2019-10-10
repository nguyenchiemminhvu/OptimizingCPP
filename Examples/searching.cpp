#include "examples.h"
#include "../timer.h"

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
            std::map<std::string, int>::iterator Iter_1;

            __NORMAL_FUNCTION
            {
                Iter_1 = map_1.find("555");
                if (Iter_1 != map_1.end())
                {
                    //std::cout << "Found" << std::endl;
                }
                else
                {
                    //std::cout << "Not found" << std::endl;
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

            std::map<charbuf<>, int> createMap_2()
            {
                std::map<charbuf<>, int> _map;
                _map["111"] = 1;
                _map["222"] = 2;
                _map["333"] = 3;
                _map["444"] = 4;
                _map["555"] = 5;
                return _map;
            }

            std::map<charbuf<>, int> map_2 = createMap_2();
            std::map<charbuf<>, int>::iterator Iter_2;

            __OPTIMIZED_FUNCTION__
            {
                Iter_2 = map_2.find("555");
                if (Iter_2 != map_2.end())
                {
                    //std::cout << "Found" << std::endl;
                }
                else
                {
                    //std::cout << "Not found" << std::endl;
                }
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

            __OPTIMIZED_FUNCTION__
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
        }

        namespace _3_Optimize_Search_In_Hashed_Tables
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
			std::map<std::string, int>::iterator Iter_1;

            __NORMAL_FUNCTION
            {
                Iter_1 = map_1.find("555");
                if (Iter_1 != map_1.end())
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

            std::unordered_map<std::string, int> map_2 = createMap_2();
			std::unordered_map<std::string, int>::iterator Iter_2;

            __OPTIMIZED_FUNCTION__
            {
                Iter_2 = map_2.find("555");
                if (Iter_2 != map_2.end())
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
