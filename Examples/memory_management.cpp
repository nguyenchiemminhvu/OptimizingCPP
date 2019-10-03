#include "examples.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>

namespace Ex
{
	namespace Memory_Management
	{
		namespace _1_Placement_Without_Allocation
		{
			class Foo
			{
				int value;
			public:
				Foo() {}
				Foo(int n) { value = n; }
				~Foo() {}
			};

			__NORMAL_FUNCTION
			{
				Foo *p_foo = new Foo[100];

				delete[] p_foo;
				p_foo = nullptr;
			}

			char buffer[1024];
			__OPTIMIZED_FUNCTION__
			{
				Foo *p_foo = new (buffer) Foo[100];

				p_foo = nullptr;
			}
		}

		namespace _2_Use_C_Style_Allocation
		{
			class Test_1
			{
			public:
				
			};

			class Test_2
			{
			public:
				void * operator new (size_t size)
				{
					return malloc(size);
				}

				void operator delete (void *p)
				{
					free(p);
				}
			};

			__NORMAL_FUNCTION
			{
				Test_1 *p = new Test_1;
				delete p;
			}

			__OPTIMIZED_FUNCTION__
			{
				Test_2 *p = new Test_2;
				delete p;
			}
		}
	}
}
