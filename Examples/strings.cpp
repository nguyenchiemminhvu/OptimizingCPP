#include "examples.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

namespace Ex
{
    namespace Strings
    {
        namespace _1_First_Attempt
        {
            namespace Eliminate_Temporary_String_Objects
            {
                std::string temp = "a b c d e";

                std::string remove_space(std::string s)
                {
                    std::string result;
                    for (int i = 0; i < s.length(); i++)
                    {
                        if (s[i] != ' ')
                            result = result + s[i];
                    }
                    return result;
                }

                __NORMAL_FUNCTION
                {
                    std::string s = remove_space(temp);
                }

                std::string remove_space_mutating(std::string &s)
                {
                    std::string result;
					result.reserve(s.length());
                    for (int i = 0; i < s.length(); i++)
                    {
						if (s[i] != ' ')
                        {
                            result += s[i];
                        }
                    }
                    return result;
                }


                __OPTIMIZED_FUNCTION__
                {
                    std::string s = remove_space_mutating(temp);
                }
            }
        }

        namespace _2_Second_Attempt
        {
            namespace Use_Better_Algorithm
            {
                std::string temp = "a b c d e";

                std::string remove_space(std::string s)
                {
                    std::string result;
                    for (int i = 0; i < s.length(); i++)
                    {
						if (s[i] != ' ')
                            result = result + s[i];
                    }
                    return result;
                }

                __NORMAL_FUNCTION
                {
                    std::string s = remove_space(temp);
                }

                std::string remove_space_erase(std::string s)
                {
                    for (size_t i = 0; i < s.length(); )
                    {
						if (s[i] == ' ')
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

                __OPTIMIZED_FUNCTION__
                {
                    std::string s = remove_space_erase(temp);
                }
            }
        }

        namespace _3_Third_Attempt
        {
			namespace Use_Character_Arrays_Instead_Of_String
			{
				std::string temp = "a b c d e";
				char *s = new char[temp.length()];

				std::string remove_space(std::string s)
				{
					std::string result;
					for (int i = 0; i < s.length(); i++)
					{
						if (s[i] != ' ')
							result = result + s[i];
					}
					return result;
				}

				__NORMAL_FUNCTION
				{
					remove_space(temp);
				}

				void remove_space_cstrings(char *des, const char *src, size_t size)
				{
					for (size_t i = 0; i < size; i++)
					{
						if (src[i] != ' ')
						{
							*des++ = src[i];
						}
					}
					*des = '\0';
				}

				__OPTIMIZED_FUNCTION__
				{
					remove_space_cstrings(s, temp.data(), temp.length());
				}
			}
        }
    }
}
