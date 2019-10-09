#include "performancetest.h"
#include "Examples/examples.h"
#include "registry.h"

#define stringify(s) #s

int main(int argc, char *argv[])
{
    InitRegistry();

    PerformanceTest::run(
		1000000,
        stringify(Ex::Strings::_1_First_Attempt::_1_Eliminate_Temporary_String_Objects)
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
