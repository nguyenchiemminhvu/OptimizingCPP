#include "performancetest.h"
#include "Examples/examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(100000,
        Ex::Strings::_3_Use_Character_Arrays_Instead_Of_String::normalFunc,
        Ex::Strings::_3_Use_Character_Arrays_Instead_Of_String::optimizedFunc
    );

    return 0;
}
