#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(100000,
        Ex::Searching::_2_Search_In_Sequence_Container::normalFunc,
        Ex::Searching::_2_Search_In_Sequence_Container::optimizedFunc
    );

    return 0;
}
