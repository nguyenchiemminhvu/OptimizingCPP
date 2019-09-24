#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(10000000,
        Ex::Data_Structures::_1_::normalFunc,
        Ex::Data_Structures::_1_::optimized_1
    );

    return 0;
}
