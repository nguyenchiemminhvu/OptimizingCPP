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

		namespace _2_Custom_Memory_Manager
		{
			__NORMAL_FUNCTION
			{

			}

			__OPTIMIZED_FUNCTION__
			{

			}
		}
	}
}
