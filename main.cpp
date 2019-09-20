#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(1000000,
        Ex::Searching::_2_Optimize_In_Hashed_KeyValue_Tables::normalFunc,
        Ex::Searching::_2_Optimize_In_Hashed_KeyValue_Tables::optimizedFunc
    );

    return 0;
}
