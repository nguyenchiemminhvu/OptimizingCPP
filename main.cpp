#include "performancetest.h"
#include "Examples/examples.h"
#include "registry.h"

#define stringify(s) #s

static Registry _registry;

int main(int argc, char *argv[])
{
    PerformanceTest::run(
        1000000,
        _registry.get(stringify(Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation))
    );

    return 0;
}
