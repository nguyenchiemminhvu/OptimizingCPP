#include "performancetest.h"
#include "timer.h"

#include <iostream>


void PerformanceTest::run(callback_function normalFunc, callback_function optimizedFunc)
{
    GetTimer()->setType(Timer::DurationType::MILISECONDS);

    if (normalFunc)
    {
        std::cout << "Run normal function...... ";
        GetTimer()->start();

        for (int64_t i = 0; i < N_TIME; i++)
        {
            normalFunc();
        }

        GetTimer()->stop();
    }

    if (optimizedFunc)
    {
        std::cout << "Run optimized function... ";
        GetTimer()->start();

        for (int64_t i = 0; i < N_TIME; i++)
        {
            optimizedFunc();
        }

        GetTimer()->stop();
    }
}
