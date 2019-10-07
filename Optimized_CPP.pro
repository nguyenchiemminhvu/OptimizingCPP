TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    timer.cpp \
    performancetest.cpp \
    Examples/criticalstatements.cpp \
    Examples/bitwise.cpp \
    Examples/strings.cpp \
    Examples/searching.cpp \
    Examples/datastructures.cpp \
    randomgenerator.cpp \
    registry.cpp \
    Examples/input_output.cpp \
    Examples/memory_management.cpp \
    CustomAllocators/Allocator.cpp \
    CustomAllocators/BlockAllocator.cpp \
    CustomAllocators/BlockAllocatorProxy.cpp \
    CustomAllocators/DynamicLinearAllocator.cpp \
    CustomAllocators/EndAllocator.cpp \
    CustomAllocators/FixedLinearAllocator.cpp \
    CustomAllocators/FreeListAllocator.cpp \
    CustomAllocators/LinearAllocator.cpp \
    CustomAllocators/ProxyAllocator.cpp \
    CustomAllocators/SmallBlockAllocator.cpp

HEADERS += \
    timer.h \
    performancetest.h \
    Examples/examples.h \
    randomgenerator.h \
    registry.h \
    CustomAllocators/Allocator.h \
    CustomAllocators/AllocatorProxy.h \
    CustomAllocators/AquaTypes.h \
    CustomAllocators/BlockAllocator.h \
    CustomAllocators/BlockAllocatorProxy.h \
    CustomAllocators/Debug.h \
    CustomAllocators/DynamicLinearAllocator.h \
    CustomAllocators/EndAllocator.h \
    CustomAllocators/FixedLinearAllocator.h \
    CustomAllocators/FreeListAllocator.h \
    CustomAllocators/LinearAllocator.h \
    CustomAllocators/PointerMath.h \
    CustomAllocators/ProxyAllocator.h \
    CustomAllocators/ScopeStack.h \
    CustomAllocators/SmallBlockAllocator.h \
    CustomContainers/Array.h \
    CustomContainers/HashMap.h \
    CustomContainers/Pool.h \
    CustomContainers/Queue.h
