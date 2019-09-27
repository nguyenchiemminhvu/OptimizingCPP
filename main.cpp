#include "performancetest.h"
#include "Examples/examples.h"
#include "registry.h"

#define stringify(s) #s

int main(int argc, char *argv[])
{
    InitRegistry();

    PerformanceTest::run(
        1000000,
        stringify(Ex::Data_Structures::_2_Map_And_Multimap::_1_Inserting_And_Deleting)
    );

    ReleaseRegisty();

    return 0;
}
