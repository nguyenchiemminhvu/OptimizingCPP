#include "performancetest.h"
#include "Examples/examples.h"
#include "registry.h"

#define stringify(s) #s

int main(int argc, char *argv[])
{
    InitRegistry();

    PerformanceTest::run(
        100000,
        stringify(Ex::Data_Structures::_2_Map_And_Multimap::_1_Inserting_And_Deleting)
    );

    ReleaseRegisty();

#if defined(_MBCS)
	system("pause");
#endif

    return 0;
}
