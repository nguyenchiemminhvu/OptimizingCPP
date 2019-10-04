#include "BlockAllocatorProxy.h"

using namespace Custom_Memory_Manager;

#if _DEBUG

BlockAllocatorProxy::BlockAllocatorProxy(BlockAllocator& allocator)
	: ProxyAllocator(allocator), _allocator(allocator)
{
}

BlockAllocatorProxy::~BlockAllocatorProxy()
{
}

size_t BlockAllocatorProxy::getBlockSize() const
{
	return _allocator.getBlockSize();
}

u8 BlockAllocatorProxy::getAlignment() const
{
	return _allocator.getAlignment();
}

#endif