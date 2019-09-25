#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(1000000,
        Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation::normalFunc,
        Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation::optimized,
        Ex::Data_Structures::_1_Vector_And_String::_1_Reallocation::optimized_1
    );

    return 0;
}
