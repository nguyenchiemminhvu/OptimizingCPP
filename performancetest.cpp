#include "performancetest.h"
#include "timer.h"

#include <iostream>


void PerformanceTest::run(int nTime,
                          callback_function normalFunc,
                          callback_function optimized_1,
                          callback_function optimized_2,
                          callback_function optimized_3,
                          callback_function optimized_4,
                          callback_function optimized_5,
                          callback_function optimized_6,
                          callback_function optimized_7)
{
    GetTimer()->setType(Timer::DurationType::MILISECONDS);

    if (normalFunc)
    {
        std::cout << "Run normal function.......... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            normalFunc();
        }

        GetTimer()->stop();
    }

    if (optimized_1)
    {
        std::cout << "Run optimized function (1)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_1();
        }

        GetTimer()->stop();
    }

    if (optimized_2)
    {
        std::cout << "Run optimized function (2)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_2();
        }

        GetTimer()->stop();
    }

    if (optimized_3)
    {
        std::cout << "Run optimized function (3)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_3();
        }

        GetTimer()->stop();
    }

    if (optimized_4)
    {
        std::cout << "Run optimized function (4)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_4();
        }

        GetTimer()->stop();
    }

    if (optimized_5)
    {
        std::cout << "Run optimized function (5)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_5();
        }

        GetTimer()->stop();
    }

    if (optimized_6)
    {
        std::cout << "Run optimized function (6)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_6();
        }

        GetTimer()->stop();
    }

    if (optimized_7)
    {
        std::cout << "Run optimized function (7)... ";
        GetTimer()->start();

        for (int64_t i = 0; i < nTime; i++)
        {
            optimized_7();
        }

        GetTimer()->stop();
    }
}
