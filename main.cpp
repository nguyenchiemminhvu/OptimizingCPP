#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(
        Ex::Expressions::_4_Double_Maybe_Better_Than_Float::normalFunc,
        Ex::Expressions::_4_Double_Maybe_Better_Than_Float::optimizedFunc
    );
    return 0;
}
