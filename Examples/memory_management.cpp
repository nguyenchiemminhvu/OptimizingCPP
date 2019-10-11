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
#include "../CustomAllocators/BlockAllocator.h"
#include "../CustomAllocators/LinearAllocator.h"
#include "../CustomAllocators/FixedLinearAllocator.h"
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

		namespace _2_Custom_Allocator
		{
			__NORMAL_FUNCTION
			{
				int *n = new int;
				delete n;

				int *p = new int[1000];
				delete[] p;
			}

			size_t		memory_size = 1024 * sizeof(int);
			void*       _memory = malloc(memory_size);
			Allocator*	_main_allocator = new (_memory)FreeListAllocator(
															memory_size - sizeof(FreeListAllocator), 
															pointer_math::add(_memory, sizeof(FreeListAllocator))
											);

			__OPTIMIZED_FUNCTION__
			{
				int *p = allocator::allocateNew<int>(*_main_allocator);
				allocator::deallocateDelete(*_main_allocator, p);

				Array<int> _arr(*_main_allocator, 1000);
			}
		}
	}
}
