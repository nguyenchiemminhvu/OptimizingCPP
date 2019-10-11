#include "examples.h"

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <Windows.h>

namespace Ex
{
	namespace Input_And_Output
	{
		namespace Reading_Files
		{
			std::ifstream file;

			__NORMAL_FUNCTION
			{
				file.open("file_to_read.txt");
				if (file.is_open())
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
				file.open("file_to_read.txt");
				if (file.is_open())
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
				char buffer[1024];
				file.open("file_to_read.txt");
				if (file.is_open())
				{
					file.rdbuf()->sgetn(buffer, sizeof(buffer));
				}
				file.close();
			}

			__OPTIMIZED_FUNCTION_2
			{
				char buffer[1024];
				file.open("file_to_read.txt");
				if (file.is_open())
				{
					file.read(buffer, sizeof(buffer));
				}
				file.close();
			}
		}

		namespace Writing_Files
		{
			std::ofstream file;

			__NORMAL_FUNCTION
			{
				file.open("file_to_write.txt");
				if (file.is_open())
				{
					file << "This string will be written into file (1)" << std::endl;
				}
				file.close();
			}

			HANDLE hFile;
			BOOL errorFlag;
			std::string line_to_write = "This string will be written into file (2)\n";
			__OPTIMIZED_FUNCTION__
			{
				hFile = CreateFile("file_to_write_2.txt", 
									GENERIC_WRITE, 
									FILE_SHARE_READ | FILE_SHARE_WRITE, 
									NULL, OPEN_EXISTING, 
									FILE_ATTRIBUTE_NORMAL, 
									NULL);
				if (hFile == INVALID_HANDLE_VALUE)
				{
					hFile = CreateFile("file_to_write_2.txt", 
										GENERIC_WRITE, 
										FILE_SHARE_READ | FILE_SHARE_WRITE, 
										NULL, 
										CREATE_NEW, 
										FILE_ATTRIBUTE_NORMAL, 
										NULL);
				}

				if (hFile != INVALID_HANDLE_VALUE)
				{
					WriteFile(hFile, line_to_write.c_str(), line_to_write.length(), NULL, NULL);	
				}
				CloseHandle(hFile);
			}
		}
	}
}
