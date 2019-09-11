#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(100000,
        Ex::Searching::_1_Use_STD_Map::normalFunc,
        Ex::Searching::_1_Use_STD_Map::optimizedFunc
    );

    return 0;
}
