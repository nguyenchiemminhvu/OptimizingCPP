#include "performancetest.h"
#include "examples.h"

int main(int argc, char *argv[])
{
    PerformanceTest::run(N_TIME,
                         Ex::Critical_Statements::Expressions::_1_Group_Constants_Together::normalFunc,
                         Ex::Critical_Statements::Expressions::_1_Group_Constants_Together::optimizedFunc);
    return 0;
}
