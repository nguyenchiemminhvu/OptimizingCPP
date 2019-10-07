#include "examples.h"

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>

namespace Ex
{
    namespace CriticalStatements
    {
        namespace _1_Expressions
        {
            namespace _1_Group_Constants_Together
            {
				int days = 0, seconds = 0;
                __NORMAL_FUNCTION
                {
                    days = 1000;
                    seconds = 24 * days * 60 * 60;
                }

                __OPTIMIZED_FUNCTION__
                {
                    days = 1000;
                    seconds = days * 86400;
                }
            }

            namespace _2_Use_LessExpensive_Operators
            {
				int x = 0;
                __NORMAL_FUNCTION
                {
                    x = 100;
                    x = x * 9;
                }

                __OPTIMIZED_FUNCTION__
                {
                    x = 100;
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

                __OPTIMIZED_FUNCTION__
                {
                    unsigned int numerator = 100;
                    unsigned int denominator = 10;

                    unsigned int q = numerator / denominator;
                    unsigned int r = numerator % denominator;
                    unsigned int test = (r >= (denominator >> 1)) ? q + 1 : q;
                }

                __OPTIMIZED_FUNCTION_1
                {
                    unsigned int numerator = 100;
                    unsigned int denominator = 10;

                    unsigned int test = (numerator + (denominator >> 1)) / denominator;
                }
            }

            namespace _4_Double_Maybe_Better_Than_Float
            {
                __NORMAL_FUNCTION
                {
                    double d = 0, t = 0, a = -9.8f, v0 = 0.0f, d0 = 100.0f;
                    d = a*t*t + v0*t + d0;
                }

                __OPTIMIZED_FUNCTION__
                {
                    float d = 0, t = 0, a = -9.8f, v0 = 0.0f, d0 = 100.0f;
                    d = a*t*t + v0*t + d0;
                }
            }
        }

        namespace _2_Control_Flows
        {
            namespace _1_Prefer_Switch_To_Compare_Integer
            {
                void f() {}
                void g() {}
                void h() {}

                __NORMAL_FUNCTION
                {
                    int n = 5;

                    if (n == 1) f();
                    else if (n == 2) g();
                    else if (n == 5) h();
                }

                __OPTIMIZED_FUNCTION__
                {
                    int n = 5;

                    switch (n)
                    {
                        case 1: f(); break;
                        case 2: g(); break;
                        case 5: h(); break;
                    }
                }
            }

            namespace _2_Prefer_Virtual_Function
            {
                class Animal
                {
                public:

                    enum AnimalType { DOG, CAT };

                    int _animalType;

                    Animal() { }

                    void speak()
                    {
                        if (_animalType == DOG)
                        {

                        }
                        else if (_animalType == CAT)
                        {

                        }
                    }

                    virtual void virtualSpeak()
                    {

                    }
                };

                class Dog : public Animal
                {
                public:
                    Dog() { _animalType == DOG; }

                    virtual void virtualSpeak()
                    {

                    }
                };

                class Cat : public Animal
                {
                public:
                    Cat() { _animalType = CAT; }

                    virtual void virtualSpeak()
                    {

                    }
                };

                __NORMAL_FUNCTION
                {
                    Dog d;
                    d.speak();

                    Cat c;
                    c.speak();
                }

                __OPTIMIZED_FUNCTION__
                {
                    Dog d;
                    d.virtualSpeak();

                    Cat c;
                    c.virtualSpeak();
                }
            }
        }

        namespace _3_Loops
        {
            namespace _1_Cache_The_Loop_Value
            {
                __NORMAL_FUNCTION
                {
                    char s[] = "This string has many space chars";
                    for (size_t i = 0; i < strlen(s); i++)
                    {
                        if (s[i] == ' ')
                            s[i] = '_';
                    }
                }

                __OPTIMIZED_FUNCTION__
                {
                    char s[] = "This string has many space chars";
                    for (size_t i = 0, len = strlen(s); i < len; i++)
                    {
                        if (s[i] == ' ')
                            s[i] = '_';
                    }
                }
            }

            namespace _2_Count_Down_Instead_Of_Up
            {
                __NORMAL_FUNCTION
                {
                    char s[] = "This string has many space chars";
                    for (size_t i = 0, len = strlen(s); i < len; i++)
                    {
                        if (s[i] == ' ')
                            s[i] = '_';
                    }
                }

                __OPTIMIZED_FUNCTION__
                {
                    char s[] = "This string has many space chars";
                    for (int i = strlen(s) - 1; i >= 0; i--)
                    {
                        if (s[i] == ' ')
                            s[i] = '_';
                    }
                }
            }
        }

        namespace _4_Functions
        {
            namespace _1_Grouping_Function_Arguments
            {
                struct S
                {
                    int i;
                    int a1, a2, a3, a4, a5, a6, a7, a8;
                };

                int i, a1, a2, a3, a4, a5, a6, a7, a8;
                S c;

                void f1(int &i, int &a1, int &a2, int &a3, int &a4, int &a5, int &a6, int &a7, int &a8)
                {

                }

                void f2(const S &c)
                {

                }

                __NORMAL_FUNCTION
                {
                    f1(i, a1, a2, a3, a4, a5, a6, a7, a8);
                }

                __OPTIMIZED_FUNCTION__
                {
                    f2(c);
                }
            }

            namespace _2_Prefer_Return_Value_As_Output_Parameters
            {
                struct S
                {
                    S() {}
                    S(int a, int b) { this->a = a; this->b = b; }
                    int a, b;
                };

                S f1(int a, int b)
                {
                    return S(a, b);
                }

                void f2(S &s, int a, int b)
                {
                    s.a = a;
                    s.b = b;
                }

                __NORMAL_FUNCTION
                {
                    S s = f1(1, 2);
                }

                __OPTIMIZED_FUNCTION__
                {
                    S s;
                    f2(s, 1, 2);
                }
            }
        }
    }
}
