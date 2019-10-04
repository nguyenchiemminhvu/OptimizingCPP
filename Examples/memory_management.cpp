#include "examples.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>
#include <array>

#include "../randomgenerator.h"
#include "../CustomAllocators/Allocator.h"
#include "../CustomAllocators/LinearAllocator.h"
#include "../CustomAllocators/FreeListAllocator.h"
#include "../CustomAllocators/DynamicLinearAllocator.h"
#include "../CustomContainers/Array.h"

using namespace Custom_Memory_Manager;

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

		namespace _3_Custom_Allocator
		{
			__NORMAL_FUNCTION
			{
				int *p = new int;
				*p = 1000;
				delete p;
			}

			size_t					memory_size = 1024;
			void*                   _memory = malloc(memory_size);
			Allocator*              _main_allocator = new (_memory)FreeListAllocator(memory_size - sizeof(FreeListAllocator), pointer_math::add(_memory, sizeof(FreeListAllocator)));

			__OPTIMIZED_FUNCTION__
			{
				int *p = allocator::allocateNew<int>(*_main_allocator);
				*p = 1000;
				allocator::deallocateDelete(*_main_allocator, p);
			}
		}
	}
}
