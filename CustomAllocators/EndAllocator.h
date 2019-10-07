#pragma once

/////////////////////////////////////////////////////////////////////////////////////////////
///////////////// Tiago Costa, 2014             
/////////////////////////////////////////////////////////////////////////////////////////////

#include "FixedLinearAllocator.h"

#include "..\CustomAllocators\CustomTypes.h"

namespace Custom_Memory_Manager
{
	class EndAllocator : public FixedLinearAllocator
	{
	public:
		EndAllocator(size_t size, void* start);
		~EndAllocator();

		void* allocate(size_t size, u8 alignment) override;

		void rewind(void* p) override;

	private:
		EndAllocator(const EndAllocator&);
		EndAllocator& operator=(const EndAllocator&);
	};
};