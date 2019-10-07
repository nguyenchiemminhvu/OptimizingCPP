#include "examples.h"
#include "../randomgenerator.h"

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>

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

				Dog d;
				Cat c;
                __NORMAL_FUNCTION
                { 
                    d.speak();
                    c.speak();
                }

                __OPTIMIZED_FUNCTION__
                {
                    d.virtualSpeak();
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
            namespace _1_Prefer_Return_Value_As_Output_Parameters
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

				S s;

                __NORMAL_FUNCTION
                {
                    s = f1(1, 2);
                }

                __OPTIMIZED_FUNCTION__
                {
                    f2(s, 1, 2);
                }
            }

			namespace _2_Function_or_Functor_or_Lambda
			{
				struct S
				{
					int _a, _b;
					S(int a, int b) { _a = a; _b = b; }
				};
				std::vector<S> createVec()
				{
					std::vector<S> _vec;
					_vec.reserve(30);
					for (int i = 0; i < 30; i++)
					{
						_vec.push_back(S(RANDOM(), RANDOM()));
					}
					return _vec;
				}

				std::vector<S> temp = createVec();
				std::vector<S> vec_1, vec_2, vec_3;

				bool compare(const S &s1, const S s2)
				{
					return s1._a < s2._a;
				}

				__NORMAL_FUNCTION
				{
					vec_1 = temp;
					std::sort(vec_1.begin(), vec_1.begin(), compare);
				}

				struct Compare
				{
					bool operator() (const S &s1, const S &s2)
					{
						return s1._a < s2._a;
					}
				};

				__OPTIMIZED_FUNCTION__
				{
					vec_2 = temp;
					std::sort(vec_1.begin(), vec_1.begin(), Compare());
				}

				__OPTIMIZED_FUNCTION_1
				{
					vec_3 = temp;
					std::sort(vec_1.begin(), vec_1.begin(), [](const S &s1, const S &s2) -> bool {return s1._a < s2._a;});
				}
			}
        }
    }
}
