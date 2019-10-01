#include "examples.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

namespace Ex
{
	namespace Input_And_Output
	{
		namespace Reading_Files
		{
			__NORMAL_FUNCTION
			{
				std::ifstream file;
				file.open("file_for_test.txt");
				if (file)
				{
					std::stringstream ss;
					std::copy(
						std::istreambuf_iterator<char>(file.rdbuf()),
						std::istreambuf_iterator<char>(),
						std::ostreambuf_iterator<char>(ss)
					);
					std::string str = ss.str();
				}
				file.close();
			}

			__OPTIMIZED_FUNCTION__
			{
				std::ifstream file;
				file.open("file_for_test.txt");
				if (file)
				{
					std::string str;
					str.assign(
						std::istreambuf_iterator<char>(file.rdbuf()),
						std::istreambuf_iterator<char>()
					);
				}
				file.close();
			}

			__OPTIMIZED_FUNCTION_1
			{
				std::ifstream file;
				file.open("file_for_test.txt");
				if (file)
				{
					
				}
				file.close();
			}
		}

		namespace Writing_Files
		{
			
		}
	}
}
