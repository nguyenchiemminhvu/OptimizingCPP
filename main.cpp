#include "performancetest.h"
#include "Examples/examples.h"
#include "registry.h"

#define stringify(s) #s

int main(int argc, char *argv[])
{
    InitRegistry();

    PerformanceTest::run(
		10000000,
        stringify(Ex::CriticalStatements::_4_Functions::_2_Function_or_Functor_or_Lambda)
    );

	/////////////////////////////////////////////////////
	//TEST ALL
	/////////////////////////////////////////////////////
	//std::vector<std::string> keys = REGISTRY()->keys();
	//for (int i = 0; i < keys.size(); i++)
	//{
	//	PerformanceTest::run(keys[i]);
	//	system("pause");
	//}

    ReleaseRegisty();

	system("pause");
    return 0;
}
