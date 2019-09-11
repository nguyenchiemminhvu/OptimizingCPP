#include "examples.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>

namespace Ex
{
    namespace Strings
    {
        namespace _1_First_Attempt
        {
            namespace _1_Eliminate_Temporary_String_Objects
            {
                std::string temp = "a b c d e";

                std::string remove_ctrl(std::string s)
                {
                    std::string result;
                    for (int i = 0; i < s.length(); i++)
                    {
                        if (s[i] >= 0x20)
                            result = result + s[i];
                    }
                    return result;
                }

                std::string remove_ctrl_2(std::string &s)
                {
                    std::string result;
                    result.reserve(s.length());
                    for (int i = 0; i < s.length(); i++)
                    {
                        if (s[i] >= 0x20)
                        {
                            result += s[i];
                        }
                    }
                    return result;
                }

                __NORMAL_FUNCTION
                {
                    std::string s = remove_ctrl(temp);
                }

                __OPTIMIZED_FUNCTION
                {
                    std::string s = remove_ctrl_2(temp);
                }
            }

            namespace _2_Eliminate_Return_String_Value
            {
                std::string temp = "a b c d e";

                std::string remove_ctrl_2(std::string &s)
                {
                    std::string result;
                    result.reserve(s.length());
                    for (int i = 0; i < s.length(); i++)
                    {
                        if (s[i] >= 0x20)
                        {
                            result += s[i];
                        }
                    }
                    return result;
                }

                void remove_ctrl_non_return(std::string &s, const std::string &temp)
                {
                    s.clear();
                    s.reserve(temp.length());
                    for (int i = 0; i < temp.length(); i++)
                    {
                        if (temp[i] >= 0x20)
                        {
                            s += temp[i];
                        }
                    }
                }

                __NORMAL_FUNCTION
                {
                    std::string s = remove_ctrl_2(temp);
                }

                __OPTIMIZED_FUNCTION
                {
                    std::string s;
                    remove_ctrl_non_return(s, temp);
                }
            }
        }

        namespace _2_Second_Attempt
        {
            namespace _1_Use_Better_Algorithm
            {
                std::string temp = "a b c d e";

                std::string remove_ctrl(std::string s)
                {
                    std::string result;
                    result.reserve(s.length());
                    for (int i = 0; i < s.length(); i++)
                    {
                        if (s[i] >= 0x20)
                            result = result + s[i];
                    }
                    return result;
                }

                std::string remove_ctrl_append(std::string s)
                {
                    std::string result;
                    result.reserve(s.length());
                    for (size_t i = 0, j = i; i < s.length(); i++)
                    {
                        for (j = i; j < s.length(); j++)
                        {
                            if (s[j] < 0x20)
                                break;
                        }
                        result.append(s, i, j - i);
                    }
                    return result;
                }

                std::string remove_ctrl_erase(std::string s)
                {
                    for (size_t i = 0; i < s.length(); )
                    {
                        if (s[i] < 0x20)
                        {
                            s.erase(i, 1);
                        }
                        else
                        {
                            i++;
                        }
                    }
                    return s;
                }

                __NORMAL_FUNCTION
                {
                    std::string s = remove_ctrl(temp);
                }

                __OPTIMIZED_FUNCTION
                {
                    std::string s = remove_ctrl_append(temp);
                    //std::string s = remove_ctrl_erase(temp);
                }
            }

            namespace _2_Use_Better_Allocator
            {
                __NORMAL_FUNCTION
                {

                }

                __OPTIMIZED_FUNCTION
                {

                }
            }
        }

        namespace _3_Use_Character_Arrays_Instead_Of_String
        {
            std::string temp = "a b c d e";
            std::string s1;
            char *s2 = new char[temp.length()];

            void remove_ctrl_non_return(std::string &s, const std::string &temp)
            {
                s.clear();
                s.reserve(temp.length());
                for (int i = 0; i < temp.length(); i++)
                {
                    if (temp[i] >= 0x20)
                    {
                        s += temp[i];
                    }
                }
            }

            void remove_ctrl_cstrings(char *des, const char *src, size_t size)
            {
                for (size_t i = 0; i < size; i++)
                {
                    if (src[i] >= 0x20)
                    {
                        *des++ = src[i];
                    }
                }
                *des = '\0';
            }

            __NORMAL_FUNCTION
            {
                remove_ctrl_non_return(s1, temp);
            }

            __OPTIMIZED_FUNCTION
            {
                remove_ctrl_cstrings(s2, temp.data(), temp.length());
            }
        }
    }
}
