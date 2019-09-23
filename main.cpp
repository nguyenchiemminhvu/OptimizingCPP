#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(100000,
        Ex::Searching::_3_Optimize_Search_In_Hashed_Tables::normalFunc,
        Ex::Searching::_3_Optimize_Search_In_Hashed_Tables::optimized_1
    );

    return 0;
}
