#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(100000,
        Ex::Strings::_2_Second_Attempt::_1_Use_Better_Algorithm::normalFunc,
        Ex::Strings::_2_Second_Attempt::_1_Use_Better_Algorithm::optimizedFunc
    );

    return 0;
}
