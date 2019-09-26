#include "performancetest.h"
#include "Examples/examples.h"
#include "registry.h"

#define stringify(s) #s

int main(int argc, char *argv[])
{
    PerformanceTest::run(
        1000000,
        stringify(Ex::Data_Structures::_1_Vector_And_String::_4_Sorting)
    );

    return 0;
}
