#include "performancetest.h"
#include "Examples/examples.h"
#include "registry.h"

#define stringify(s) #s

int main(int argc, char *argv[])
{
    InitRegistry();

    PerformanceTest::run(
        10000000,
        stringify(Ex::Data_Structures::_2_Map)
    );

	/////////////////////////////////////////////////////
	//TEST ALL
	/////////////////////////////////////////////////////
	//std::vector<std::string> keys = REGISTRY()->keys();
	//for (int i = 0; i < keys.size(); i++)
	//{
	//	PerformanceTest::run(
	//		1000000,
	//		keys[i]
	//	);

	//	system("pause");
	//}

    ReleaseRegisty();

#if defined(_MBCS)
	system("pause");
#endif

    return 0;
}
