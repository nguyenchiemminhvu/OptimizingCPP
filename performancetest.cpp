#include "performancetest.h"
#include "timer.h"

#include <chrono>
#include <iostream>
#include <locale>

#define stringify(s) #s

void PerformanceTest::run(int nTime,
                          callback_function normalFunc,
                          callback_function optimized,
                          callback_function optimized_1,
                          callback_function optimized_2,
                          callback_function optimized_3,
                          callback_function optimized_4,
                          callback_function optimized_5,
                          callback_function optimized_6,
                          callback_function optimized_7)
{
	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_normal;
    if (normalFunc)
    {
        std::cout << "Run normal function.......... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            normalFunc();
        }

        GetTimer()->stop();
		d_normal = GetTimer()->getDuration();
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized;
    if (optimized)
    {
        std::cout << "Run optimized function....... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized();
        }

        GetTimer()->stop();
		d_optimized = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized_1;
    if (optimized_1)
    {
        std::cout << "Run optimized function (1)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_1();
        }

        GetTimer()->stop();
		d_optimized_1 = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized_1).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized_2;
    if (optimized_2)
    {
        std::cout << "Run optimized function (2)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_2();
        }

        GetTimer()->stop();
		d_optimized_2 = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized_2).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized_3;
    if (optimized_3)
    {
        std::cout << "Run optimized function (3)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_3();
        }

        GetTimer()->stop();
		d_optimized_3 = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized_3).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized_4;
    if (optimized_4)
    {
        std::cout << "Run optimized function (4)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_4();
        }

        GetTimer()->stop();
		d_optimized_4 = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized_4).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized_5;
    if (optimized_5)
    {
        std::cout << "Run optimized function (5)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_5();
        }

        GetTimer()->stop();
		d_optimized_5 = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized_5).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized_6;
    if (optimized_6)
    {
        std::cout << "Run optimized function (6)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_6();
        }

        GetTimer()->stop();
		d_optimized_6 = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized_6).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }

	std::chrono::time_point<std::chrono::high_resolution_clock>::duration d_optimized_7;
    if (optimized_7)
    {
        std::cout << "Run optimized function (7)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_7();
        }

        GetTimer()->stop();
		d_optimized_7 = GetTimer()->getDuration();
		auto d_normal_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_normal).count();
		auto d_optimized_count = (double)std::chrono::duration_cast<std::chrono::milliseconds>(d_optimized_7).count();
		std::cout << "============================> " << 100 - (d_optimized_count / d_normal_count) * 100 << "%" << std::endl;
    }
}

void PerformanceTest::run(std::string _namespace)
{
	FuncPtr _functions = REGISTRY()->get(_namespace);

	std::cout.imbue(std::locale(""));
	std::cout << std::endl;
    std::cout << "Run test case " << _namespace;
	std::cout << " in " << _functions._nTime << " (times)" << std::endl;

    run(
        _functions._nTime,
        _functions.f_normal,
        _functions.f_optimized,
        _functions.f_optimized_1,
        _functions.f_optimized_2,
        _functions.f_optimized_3,
        _functions.f_optimized_4,
        _functions.f_optimized_5,
        _functions.f_optimized_6,
        _functions.f_optimized_7
    );

    std::cout << "" << std::endl;
}

void PerformanceTest::run(int nTime, std::string _namespace)
{
	FuncPtr _functions = REGISTRY()->get(_namespace);

	std::cout.imbue(std::locale(""));
	std::cout << std::endl;
	std::cout << "Run test case " << _namespace;
	std::cout << " in " << nTime << " (times)" << std::endl;

	run(
		nTime,
		_functions.f_normal,
		_functions.f_optimized,
		_functions.f_optimized_1,
		_functions.f_optimized_2,
		_functions.f_optimized_3,
		_functions.f_optimized_4,
		_functions.f_optimized_5,
		_functions.f_optimized_6,
		_functions.f_optimized_7
	);

	std::cout << "" << std::endl;
}
